#include <iostream>
using namespace std;

void f(int);
void f(int&);

int main() {
    int32_t i = 123;
    cout << i << "\n";
    cout << INT32_MAX << "\n";
    int32_t const & r = i;
    cout << r << "\n";
}
