#include <type_traits>
using namespace std;
template <typename T>
concept IsInteger = std::is_integral_v<T>;
template <typename T1>
struct A {
  // template <typename I>
  template <IsInteger  I>
  struct B;
};
template <typename T1>
template <IsInteger I>
struct A<T1>::B {
  I value;
};

int main() {
  A<int>::B<int> ib;
  // A<int>::B<double> id{3};
}