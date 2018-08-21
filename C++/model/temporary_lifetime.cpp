#include <iostream>
using namespace std;

class Temp {
public:
	Temp() {
		cout << __func__ << endl;
	}

	~Temp() {
		cout << __func__ << endl;
	}

	Temp foo() {
		return *new Temp();
	}

	operator int() {
		cout << __func__ << endl;
		return 1;
	}
};

int main() {
	cout << __LINE__ << endl;
	Temp t;
	cout << __LINE__ << endl;
	Temp tt;
	cout << __LINE__ << endl;
	if (t.foo() || tt.foo())
		;
	cout << __LINE__ << endl;
	if (t.foo() && tt.foo())
		;
	cout << __LINE__ << endl;

/*
深度探索C++对象模型：272页；
在“||”就是一个full-expression，在这个表达式完整的求出值之前，temporary object不会被释放，
也就是直到进行到右边的括号“）”之前。
25
Temp
27
Temp
29
Temp
operator int
~Temp
32
Temp
operator int
Temp
operator int
~Temp
~Temp
35
~Temp
~Temp

所以|| 才算是full-expression
*/
	return 0;
}

