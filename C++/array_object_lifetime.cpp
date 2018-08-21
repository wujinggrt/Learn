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

/*
深度探索C++对象模型：262页；
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
~B
~A
*/
	return 0;
}
