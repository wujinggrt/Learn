#include <iostream>
#include <type_traits>
using namespace std;

struct A {
  using Int = int;
};

struct B : A {
};

int main() {
  int i{20};
  int&& rri = std::move(i);
  int j = rri;
  cout << j << endl;
  B::Int bi{4};
  cout << bi << endl;
}