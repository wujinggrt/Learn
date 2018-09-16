#include <iostream>
using namespace std;

int g_count = 0;

struct Data
{
    Data(int i = 0)
    {
        cout << "Data ctor: param: i: " << i <<  endl;
    }

    Data(const Data &d)
    {
        cout << "Cpy ctor" << endl;
    }
};

class A
{
public:
    A(int i = 1)
        : _ci{i}
    {
        cout << "A ctor 1 param: _i:" << _ci << endl;
    }

    A(int d, int i, int dd)
        : _d{d},
        _ci{i},
        _dd{dd}
    {
        cout << "A ctor 2 param: _i:" << _ci << endl;
    }

    const Data _d{99999};
    const int _ci{10};
    const Data _dd{88888};
};

int main()
{
    A a;
    A aa(11);
    // 如果调用的为另外一个版本的ctor（没有在初始值列表中显示构造_d，那么是否调用类内初始值）
    A aaa(2, 22, 3);
// Data ctor: param: i: 99999
// Data ctor: param: i: 88888
// A ctor 1 param: _i:1
// Data ctor: param: i: 99999
// Data ctor: param: i: 88888
// A ctor 1 param: _i:11
// Data ctor: param: i: 2
// Data ctor: param: i: 3
// A ctor 2 param: _i:22

    // OK, 类内初始值(in-class initializer)是在构造函数中没有在初始值列表中初始化
    // 那类内初始值将会起作用,
    // 由打印出的顺序来看，这个类内初始值应该是像第二个构造函数一样被隐式添加到初始值列表中:
    return 0;
}