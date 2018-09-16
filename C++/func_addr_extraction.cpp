#include <iostream>
using namespace std;

void f()
{
    cout << "Hehe" << endl;
}

int main()
{
    auto addre_f = f;
    auto addre_f_2 = &f;

    cout << "addre_f: " << addre_f << endl;
    cout << "addre_f_2: " << addre_f_2 << endl;
    
    addre_f();
    addre_f_2();

    cout << typeid(addre_f).name() << endl;
    cout << typeid(addre_f_2).name() << endl;
/*
addre_f: 1
addre_f_2: 1
Hehe
Hehe
PFvvE
PFvvE
*/
    return 0;
}