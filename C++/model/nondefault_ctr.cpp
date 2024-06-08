#include <iostream>
using namespace std;

class Foo {
	public:
		Foo() : i(10) {cout << "default Foo" << endl;}
		Foo(int i) : i (i) {cout << "with params foo" << endl;}

		int i;
};

class Bar {
	public:
		Bar()=default;
		Bar(int i) : i(i) { cout << "with params Bar" << endl;}

		Foo foo;
		int i;
};

int main() {
	Bar bar;
	return 0;
}
