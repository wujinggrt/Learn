#include <iostream>
using namespace std;

class Hehe {
	public:
		Hehe() : i(0) { cout << "ctr" << __LINE__ << endl;}  
		~Hehe() { cout << "dctr" << __LINE__ << endl;}
		Hehe(const Hehe &h) { 
			cout << "cpy" << __LINE__ << endl; 
			this->i = h.i; 
		}
		Hehe& operator=(const Hehe &h) {
			cout << "=" << __LINE__ << endl;
			this->i = h.i;
			return *this;
		}
			
		int i;
};

Hehe func() {
	Hehe h;
	cout << __func__ <<  __LINE__ << endl;
	return h;
}

Hehe* func2() {
	cout << __func__ <<  __LINE__ << endl;
	return new Hehe();
}
	
void test() {
	cout << __func__ << __LINE__ << endl;
	// NRV，这里并没有调用copy constructor
	Hehe h = func();
	cout << __LINE__ << endl;
	// 指针调用，所以并没有copy constructor调用
	Hehe* i = func2();
	cout << __LINE__ << endl;
	// 调用copy constructor
	Hehe j = *func2();
	cout << __LINE__ << endl;
	cout << __func__ <<  __LINE__ << endl;
}
/*
结果：
test33
ctr6
func23
36
func228
ctr6
39
func228
ctr6
cpy9
42
test43
dctr7
dctr7
*/

int main() {
	test();
	return 0;
}
