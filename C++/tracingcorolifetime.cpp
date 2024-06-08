#include <iostream>
#include <coroutine>
using namespace std;

struct Task {
  struct promise_type;
  using CoroutineHandle = coroutine_handle<promise_type>;
  struct promise_type {
    Task get_return_object() {
      return CoroutineHandle::from_promise(*this);
    }
    suspend_always initial_suspend() { return {}; }
    suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() { }
    void return_void() {}
  };

  Task(CoroutineHandle handle) : handle{std::move(handle)} {}
  ~Task() {
    if (handle) {
      handle.destroy();
    }
  }

  CoroutineHandle handle;
};

struct Awaiter {
  Awaiter() {
    cout << "Awater ===> ctor\n";
  }
  ~Awaiter() {
    cout << "Awaiter <=== dtor\n";
  }

  bool await_ready() { return false ;}
  void await_suspend(std::coroutine_handle<>) { }
  void await_resume() {}
};

struct A {
  A() {
    cout << "A ===> ctor\n";
  }
  ~A() {
    cout << "A <=== dtor\n";
  }

  Awaiter operator co_await() {
    cout << "A is casting to Awaiter\n";
    return {};
  }
};

Task task_test() {
  cout << __FUNCTION__ << " Task test, co_await starting\n";
  co_await A{};
  cout << __FUNCTION__ << " After co_await\n";
}

template <typename T1>
struct TmpStruct1 { T1 t;};

template <typename T2>
struct Tmp2 { T2 t; };

template <typename D>
concept HasDInt = requires (D d) { typename D::DInt; };

template <typename D>
  requires HasDInt<D>
struct Base {
  using Int = int;
  using BInt = typename D::DInt;
  int a;
};

struct D1 : Base<D1> {
  using DInt = int;
  int d1;
};

struct D2 : D1 {
  int d2;
};

template <template <typename T1> typename TT, typename T>
struct MYT {};



int main() {
  auto t = task_test();
  cout << "Main ===> resuming\n";
  t.handle.resume();
  cout << "Main === resumed\n";
  t.handle.resume();
  cout << "Main <=== resumed\n";
  Tmp2<TmpStruct1<int>> tmp;

  D2 d2;
  D2::Int di{342};
  cout << d2.a << di << endl;
}