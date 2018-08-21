#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "ctr" << endl;
    }

    A(int i) {
        cout << "p" << endl;
    }

    A(const A& a) {
        cout << "cpy" << endl;
    }

};

int main() {
    A a = A(2);
    A b;
    A c = b;
// p
// ctr
// cpy   
    return 0;
}