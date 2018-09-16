#include <iostream>
using namespace std;

class A
{
    public:
    A(int i)
    :_i(i)
    {
    }

    protected:
    void f() 
    {
        cout << __LINE__ << endl;
    }

    private:
    const int _i;
};

class B : public A
{
    public:
    void test()
    {
        A::f();
    }
};

int main()
{
    B b;
    b.test ();

    return 0;
}