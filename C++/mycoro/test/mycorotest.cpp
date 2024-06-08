#include <gtest/gtest.h>

#include <coroutine>

#include "../mynestcoro.hpp"

template <typename Ref>
class TaskTest {
  using RemoveReference = std::remove_cvref_t<Ref>;
  using RightReference = std::add_rvalue_reference_t<RemoveReference>;
  using Yielded = RightReference;
  using Value = RemoveReference;

 public:
  struct promise_type;
  using CoroutineHandle = std::coroutine_handle<promise_type>;
  friend class PromiseErased<Yielded>;

  TaskTest(CoroutineHandle handle) : handle{std::move(handle)} {}
  ~TaskTest() {
    if (handle) {
      handle.destroy();
    }
  }

  struct promise_type : PromiseErased<Yielded> {
    TaskTest get_return_object() {
      return CoroutineHandle::from_promise(*this);
    }
  };

  Value value() const { return *handle.promise().value(); }
  void resume() {
    if (handle && !handle.done()) {
      handle.resume();
    }
  }

 private:
  CoroutineHandle handle;
};

TaskTest<int> yield_rvalue() { co_yield 1; }

TaskTest<int> yield_lvalue(int i) { co_yield i; }

TEST(PromiseErasedTest, YieldValueTest) {
  auto task_rvalue = yield_rvalue();
  task_rvalue.resume();
  EXPECT_EQ(task_rvalue.value(), 1);
  int lvalue = 10;
  auto task_lvalue = yield_lvalue(lvalue);
  task_lvalue.resume();
  EXPECT_EQ(task_lvalue.value(), lvalue);
}

#if 0
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif