#include <iostream>
using namespace std;

struct S {
    bool b;
    int i;
};

#define MY_OFFSETOF(s, m) \
    reinterpret_cast<size_t>(&reinterpret_cast<const char&>(reinterpret_cast<s*>(0)->m))

#define A_OFFSETOF(s, m) ((::size_t)&reinterpret_cast<const char&>((((s*)0)->m)))

int main() {
    cout << MY_OFFSETOF(S, i) << "\n";
    // offsetof
}