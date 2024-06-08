module;
#include <iostream>
export module Mod2;
import :Bar;

export void foo() {
    std::cout << "foo\n";
    bar2();
}

// mod2foo.cpp有定义，随后在module implementation units中实现foo即可
export struct Foo {
    void foo();
};

// 仅仅声明，没有定义，在module implementation units中
// 全部定义和实现Bar，也不能够输出给外部，看到的都是has incomplete type and
// cannot be defined
export struct Bar;