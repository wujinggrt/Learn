#include <cassert>
#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>
#include <memory>
#include <type_traits>
#include <variant>

namespace yumi {

struct Noncopyable {
  Noncopyable() = default;
  Noncopyable& operator=(const Noncopyable&) = delete;
};

struct Immovable {
  Immovable() = default;
  Immovable& operator=(Immovable&&) = delete;
};

template <typename Yielded>
class PromiseErased : Noncopyable, Immovable {
  static_assert(std::is_reference_v<Yielded>);
  using YieldedRemoveReference = std::remove_reference_t<Yielded>;
  using YieldedRemoveCVRef = std::remove_cvref_t<Yielded>;
  using ValuePtr = std::add_pointer_t<Yielded>;
  using CoroutineHandle = std::coroutine_handle<PromiseErased>;

  struct SubyieldState;
  struct FinalAwaiter;
  struct CopyAwaiter;
  template <typename CoroutineInterface>
  struct RecursiveAwaiter;

  PromiseErased(const PromiseErased&) = delete;

 public:
  std::suspend_always initial_suspend() const noexcept { return {}; }

  std::suspend_always yield_value(Yielded value) noexcept {
    this->bottom_value() = std::addressof(value);
    return {};
  }

  CopyAwaiter yield_value(const YieldedRemoveReference& value) noexcept
    requires(std::is_rvalue_reference_v<Yielded> &&
             std::constructible_from<YieldedRemoveReference,
                                     const YieldedRemoveReference&>)
  {
    // We cannot directly assign the addressof value to bottom_value() with
    // the const qualifier. Storing it into another proper place is a way out of
    // this dilemma.
    //
    // It is a bad idea to copy as a local variable and assgin the addressof it.
    // After returning the awaiter object, backing stack makes the
    // dereference of the address of the copied value unpredictable.
    //
    // YieldedRemoveCVRef stashed{value}; // BAD, lifetime issue.
    // this->bottom_value() = std::addressof(stashed); // BAD
    return {value, bottom_value()};
  }

  void return_void() const noexcept {}


  FinalAwaiter final_suspend() noexcept { return {}; }

  void unhandled_exception() {
    if (nest_.is_bottom()) {
      throw;
    } else {
      this->except_ = std::current_exception();
    }
  }

  ValuePtr& bottom_value() noexcept { return nest_.bottom_value(); }

  ValuePtr& value() noexcept { return nest_.value(); }

 private:
  SubyieldState nest_;
  // 可以复用为context
  std::exception_ptr except_;
};

template <typename Yielded>
struct PromiseErased<Yielded>::SubyieldState {
  struct Frame {
    CoroutineHandle bottom;
    CoroutineHandle parent;
  };
  struct BottomFrame {
    CoroutineHandle top;
    ValuePtr value;
  };
  std::variant<BottomFrame, Frame> stack;

  bool is_bottom() const noexcept {
    return !std::holds_alternative<Frame>(this->stack);
  }

  CoroutineHandle& top() noexcept {
    if (auto* frame = std::get_if<Frame>(&this->stack)) {
      return frame->bottom.promise().nest_.top();
    }
    auto* bottom_frame = std::get_if<BottomFrame>(&this->stack);
    assert(bottom_frame);
    return bottom_frame->top;
  }

  // assumes that we are top, subyield is the coroutine that should be pushed.
  void push(CoroutineHandle self, CoroutineHandle subyield) noexcept {
    assert(&self.promise().nest_ == this);
    assert(this->top() == self);
    subyield.promise().nest_.jump_in(subyield, self);
  }

  // only used to resume a coroutine, so we discard the promise type.
  std::coroutine_handle<> pop() noexcept {
    if (auto* frame = std::get_if<Frame>(&this->stack)) {
      auto parent = frame->parent;
      this->top() = parent;
      return parent;
    }
    return std::noop_coroutine();
  }

  // we cannot transform a SubyieldState to CoroutineHandle, so it is
  // necessary to pass it as parameter.
  void jump_in(CoroutineHandle self, CoroutineHandle stack_top) {
    assert(this->is_bottom());
    assert(&self.promise().nest_ == this);
    auto target_bottom = stack_top;
    // presume that stack_top has only one stack frame and we are the second
    // frame.
    if (auto frame = std::get_if<Frame>(&stack_top.promise().nest_.stack)) {
      target_bottom = frame->bottom;
    }
    assert(target_bottom.top() == stack_top);
    target_bottom.promise().nest_.top() = self;
    this->stack = Frame{.bottom = target_bottom, .parent = stack_top};
  }

  ValuePtr& bottom_value() noexcept {
    if (auto* bottom_frame = std::get_if<BottomFrame>(&this->stack)) {
      return bottom_frame->value;
    }
    auto* frame = std::get_if<Frame>(&this->stack);
    assert(frame);
    return frame->bottom.promise().nest_.value();
  }

  ValuePtr& value() noexcept {
    assert(this->is_bottom());
    auto* bottom_frame = std::get_if<BottomFrame>(&this->stack);
    return bottom_frame->value;
  }
};

template <typename Yielded>
struct PromiseErased<Yielded>::FinalAwaiter {
  bool await_ready() noexcept { return false; }

  template <typename Promise>
  auto await_suspend(std::coroutine_handle<Promise> handle) noexcept {
    static_assert(
        std::is_pointer_interconvertible_base_of_v<PromiseErased, Promise>);
    auto& nest = handle.promise().nest_;
    return nest.pop();
  }

  void await_resume() noexcept {}
};

template <typename Yielded>
struct PromiseErased<Yielded>::CopyAwaiter {
  YieldedRemoveCVRef value;
  ValuePtr& bottom_value;

  constexpr bool await_ready() noexcept { return false; }

  template <typename Promise>
  void await_suspend(std::coroutine_handle<Promise> handle) noexcept {
    static_assert(
        std::is_pointer_interconvertible_base_of_v<PromiseErased, Promise>);
    bottom_value = std::addressof(value);
  }

  constexpr void await_resume() noexcept {}
};

template <typename Yielded>
template <typename CoroutineInterface>
struct PromiseErased<Yielded>::RecursiveAwaiter {
  CoroutineInterface interface;
  static_assert(std::is_same_v<typename CoroutineInterface::Yielded, Yielded>);
  RecursiveAwaiter(CoroutineInterface interface) noexcept
      : interface{std::move(interface)} {}

  constexpr bool await_ready() const noexcept { return false; }

  template <typename Promise>
  std::coroutine_handle<> await_suspend(
      std::coroutine_handle<Promise> handle) noexcept {
    static_assert(
        std::is_pointer_interconvertible_base_of_v<PromiseErased, Promise>);
    auto current_stack = CoroutineHandle::from_address(handle.address());
    auto subyield_coroutine =
        CoroutineHandle::from_address(this->interface.handle.address());
    current_stack.promise().nest_.push(current_stack, subyield_coroutine);
    return subyield_coroutine;
  }

  void await_resume() {
    if (auto e = interface.handle.promise().except_) {
      std::rethrow_exception(e);
    }
  }
};
}