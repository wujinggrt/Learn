#include <any>
#include <concepts>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>
#include <type_traits>
using namespace std;
template <typename _Ref, typename _Val>
using _Reference_t = conditional_t<is_void_v<_Val>, _Ref&&, _Ref>;
/// Type yielded by a generator whose _Reference type is _Reference.
template <typename _Reference>
using _Yield_t =
    conditional_t<is_reference_v<_Reference>, _Reference, const _Reference&>;

/// _Yield_t * _Reference_t
template <typename _Ref, typename _Val>
using _Yield2_t = _Yield_t<_Reference_t<_Ref, _Val>>;

_Yield2_t<int, void> c = 'c';

struct A {};
struct B : A {};

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    cout << is_same_v<_Yield2_t<int, void>, char&&> << "\n";
    std::cout << std::is_pointer_interconvertible_base_of_v<A, B> << "\n";
    int i = 3;
    int* p = &i;
    auto iter = vec.begin();
    auto i2 = static_cast<int&>(*iter);
    auto i3 = static_cast<int&&>(*iter);
    int& ri = i;
    auto i4 = static_cast<int&&>(ri);
  cout << "Hello\n";
}