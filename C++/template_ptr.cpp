#include <iostream>
#include <string>
using namespace std;

template<typename T>
void f(T p)
{
    cout << *p << endl;
}

template<typename T>
void f2(const T &p)
{
    cout << p << endl;
}

class A
{
public:
    A(string s = "Hello")
        : _s(new string(s)) {}

    string& operator*() const { return *_s; }
    string* operator->() const { return _s; }

private:
    string *_s;
};

int main()
{
    int *p = new int(5);
    f(p);
// 5

    A a(string("hehe"));
    cout << "*a: " << *a << endl;
    cout << "a->size(): " << a->size() << endl;

    f2(*p);

    return 0;
}