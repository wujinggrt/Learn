#include <iostream>
using namespace std;

template<typename T> 
class A;

class B;

template<typename T>
class A
{
friend class B;

};

class B : public A<B>
{
public:
    B()
    {
        cout << __func__ << '\n';
    }

};

class C : B
{
public:
    C()
    {
        cout << __func__ << '\n';
    }
};

int main()
{
    B b;
    C c;
    return 0;
}