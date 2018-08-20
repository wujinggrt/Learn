#include <iostream>
using namespace std;

class Base1 {
public:
	Base1() :_i(f()) {
		f();
	}

	Base1(int i) : _i(i) {
		cout << _i << endl;
		f();
	}
	
	virtual int f() {
		cout << "Base1" << 10 << endl;
		return 10;
	}

	int _i;
};

class Base2 : public virtual Base1 {
public:
	Base2() : Base1(f()) {
		f();
	}

	int f() {
		cout << "Base2" << 100 << endl;
		return 100;
	}
};

int main() {
	Base1 b1;
	Base2 b2;
	
//	b2.f();
	return 0;
}
