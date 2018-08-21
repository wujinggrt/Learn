#include <iostream>
using namespace std;

void f(int &i) {
    i = 0;
    cout << i << endl;
}

void f(int i) {
    cout << i << endl;
}

/*
不能通过编译，无法决议出调用那个函数，
ambiguous
*/
int main() {
    int i = 4;
    f(i);
    return 0;
}