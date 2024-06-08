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
	cout << "Base1 b1:" << endl;
	Base1 b1;

	cout << "Base2 b2:" << endl;
	Base2 b2;

/*
Base1 b1:
Base110
Base110
Base2 b2:
Base2100
100
Base110
Base2100
*/

	return 0;
}
