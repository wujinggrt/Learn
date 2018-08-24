#include <iostream>
using namespace std;

int a() {
 return 2;
}
/*
 * b()表示一个函数
 * (*b())说明我们可以对一个函数调用结果解引用
 * (*b())()表示解引用函数调用之后是一个函数
 * int (*b())() 表示解引用函数调用之后是一个函数，函数的返回值是int类型的，即返回一个函数指针
int (*b())() {
 return a;
}
*/
//C++11的定义方式
auto b() -> int (*) (){
 return &a;//直接a也是可以的
}
int main()
{
 std::cout<<(*b())()<<std::endl;
 std::cout<<b()()<<std::endl;

 return 0;
}