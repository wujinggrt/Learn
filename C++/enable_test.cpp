#include <iostream>
#include <string>
using namespace std;

template<bool B, class T = void>
struct my_enable_if {};
 
template<class T>
struct my_enable_if<true, T> { typedef T type; };

// void f(int i) {
void f(int i, typename my_enable_if<std::is_integral<double>::value>::type *p = nullptr) {
    cout << "with i\n";
}

// void f(void, void) { // wrong
void f(void) {
    cout << "Void\n";
}

int main() {
    f(1);
    f();
}