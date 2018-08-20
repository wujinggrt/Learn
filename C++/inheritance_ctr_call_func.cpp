#include <iostream>
using namespace std;

class Base1 {
public:
	Base1() {
		f();
	}
	
	virtual void f() {
		cout << "Base1" << endl;
	}
};

class Base2 : public virtual Base1 {
public:
	// 错误的，下一行代码，因为vptr还没有初始化
	// Base2():f() {
	Base2():f() {
		f();
	}

	void f() {
		cout << "Base2" << endl;
	}
};

int main() {
	Base1 b1;
	Base2 b2;
	
	b2.f();
	return 0;
}
