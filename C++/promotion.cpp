#include <iostream>
using namespace std;

int main() {
    int i = 10;
    int j = 3;
    int k = 2;
    double d = 2.0;

    auto a = i / j;
    // i i
// d d
// 3 3
    cout << typeid(a).name()  << " " << typeid(i / j).name() << endl;
    cout << typeid(d).name()  << " " << typeid(i / d).name() << endl;
    cout << a  << " " << (i / j) << endl;

    int *p = &i;
    cout << typeid(p).name() << endl;
    decltype(p) dp;
    cout << typeid(dp).name() << endl;
    dp = &i;
    cout << *dp << endl;
    return 0;
}