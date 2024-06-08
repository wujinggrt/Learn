#include <iostream>
using namespace std;

class A {
	public:
		A() {
			cout << __func__ << endl;
		}

		~A() {
			cout << __func__ << endl;
		}
};

class B : public A {
public:
	B() {
		cout << __func__ << endl;
	}

	~B() {
		cout << __func__ << endl;
	}
};

int main() {
	cout << __LINE__ << endl;
	A *a = new B[5];
	cout << __LINE__ << endl;
	delete [] a;
	cout << __LINE__ << endl;

	B *b = new B[5];
	cout << __LINE__ << endl;
	delete [] b;
	cout << __LINE__ << endl;

	B c;
	cout << __LINE__ << endl;

	A *aa = new B[5];
	cout << __LINE__ << endl;

/*
深度探索C++对象模型：262页；
使用base class声明的derived class的对象数组，在调用delete [] 的时候，
只会调用A::~A，derived class的析构函数不会调用，直到main结束，都没有子类的析构函数调用的信息。
27
A
B
A
B
A
B
A
B
A
B
29
~A
~A
~A
~A
~A
31
A
B
A
B
A
B
A
B
A
B
34
~B
~A
~B
~A
~B
~A
~B
~A
~B
~A
36
A
B
39
A
B
A
B
A
B
A
B
A
B
42
~B
~A
*/
	return 0;
}
