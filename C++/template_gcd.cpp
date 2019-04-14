#include <iostream>
using namespace std;

template<int a, int b>
struct gcd {
    static const int value = gcd<b, a % b>::value;
};

template<int a>
struct gcd<a, 0> {
    static const int value = a;
};

int main() {
    cout << gcd<54, 24>::value << '\n'; // 6
}