#include <iostream>
using namespace std;

// 测试STL源码剖析57页set_malloc_handler语法
void (*pf(void (*f)()))() 
{
    f();

    return f;
}

void print()
{
    cout << __func__ << endl;
}

void* another_f(void (*f)())
{
    f();

    return f;
}

int main() 
{
    auto f = pf(print);
    f();
// 输出：
// print
// print

    auto f2 = another_f(print);
    f2();
    

    return 0;
}