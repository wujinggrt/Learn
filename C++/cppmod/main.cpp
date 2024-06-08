#include <atomic>
#include <exception>
import <iostream>;
#include <type_traits>
#include <variant>
import Mod2;

template <typename T>
concept IsPointer = requires(T p) {
  *p;
  p == nullptr;
};

template <typename T>
  requires IsPointer<T>
void myf(T p) {
  std::cout << *p << "\n";
}


int main() {
  foo();
  Foo f;
  f.foo();
  std::variant<std::exception_ptr, std::atomic<void*>, Foo> v1{};
  std::cout << sizeof(std::exception_ptr) << "\n"
            << sizeof(std::atomic<void*>) << "\n"
            << sizeof(v1) << "\n";
  int i{10};
  showInt(i);
}