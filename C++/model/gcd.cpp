#include <iostream>

template<int a, int b>
struct gcd {
	static const int value = gcd<b, a % b>::value;
};

template<int a>
struct gcd<a, 0> {
	static const int value = a;
};

int main() {
	std::cout << gcd<50, 30>::value << std::endl;
	return 0;
}
