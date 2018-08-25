#include <iostream>
using namespace std;

template<typename T>
void f(T p)
{
    cout << *p << endl;
}

int main()
{
    int *p = new int(5);
    f(p);
// 5
    return 0;
}