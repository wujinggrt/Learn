#include <any>
#include <coroutine>
#include <cstdlib>
#include <generator>
#include <iostream>
#include <memory>
#include <string_view>
using namespace std;

struct A {
  A() { cout << "A\n"; }
  ~A() { cout << "~A\n"; }
};

struct MyAwaiter {
  auto await_ready() {
    cout << "ready\n";
    return false;
  }
  auto await_suspend(auto hdl) {
    cout << "Suspend\n";
    return false;
  };
  auto await_resume() { cout << "Resumed\n"; }

  MyAwaiter() { cout << "MyAwaiter\n"; }
  ~MyAwaiter() { cout << "~MyAwaiter\n"; }
};

struct task {
  struct promise_type;
  using handle = coroutine_handle<promise_type>;
  struct promise_base {
    auto initial_suspend() { return suspend_always{}; }
    auto return_void() {}
    auto final_suspend() noexcept { return suspend_always{}; }
    auto yield_value(std::shared_ptr<A> i) {
      cout << "SHared\n";
      return MyAwaiter{};
    }
    auto unhandled_exception() { exit(EXIT_FAILURE); }
  };
  struct promise_type : promise_base {
    auto get_return_object() noexcept {
      return task{handle::from_promise(*this)};
    }
  };

  task(handle hdl) : hdl{hdl} {}
  ~task() {
    if (hdl || hdl.done()) {
      hdl.destroy();
    }
  }
  task(const task&) = delete;
  task& operator=(const task&) = delete;
  void resume() {
    if (hdl && !hdl.done()) {
      hdl.resume();
    }
  }
  handle hdl;
};

task foo() noexcept {
  cout << "Hell foo\n";
  co_await MyAwaiter{};
  cout << "After coawait\n";
  {
    cout << "Scope start\n";
    co_yield make_shared<A>();
    cout << "Scope end\n";
  }
  cout << "After co_yield\n";
}

int main() {
  auto g = foo();
  coroutine_handle<> h1 = task::handle::from_promise(g.hdl.promise());
  cout << (h1 == g.hdl);
  std::cout << '\n';
}