module;
#include <iostream>
module Mod2;

void Foo::foo() {
  std::cout << "Foo::foo\n";
  bar2();
}

struct Bar {
  void bar() {
    bar();
  }
};