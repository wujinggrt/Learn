#include <iostream>
using namespace std;

class Hehe {
	public:
		Hehe() : _i(1) {
			cout << __func__ << endl;
		}
		
		~Hehe() {
			cout << __func__ << endl;
		}

		int _i;
};

int main() {
	int i;
	double d = 4.396;
	i = static_cast<int>(d);
	cout << i << " " << d << endl;
	
	// ASCII of 'a' is 97
	char c = 'a';
	char *pc = &c;
	// 下一行编译器会报错
	// int i = reinterpret_cast<int>(pc);
	int *p = reinterpret_cast<int *>(pc);
	cout << c << " " << typeid(c).name() << endl;
	cout << *pc << " " << typeid(pc).name() << endl;
	cout << *p << " " << typeid(p).name() << endl;

	cout << __LINE__ << endl;
	Hehe *ph = new Hehe();
	cout << __LINE__ << endl;
	int *pi = reinterpret_cast<int *>(ph);
	cout << __LINE__ << endl;
	cout << *pi << " " << typeid(pi).name() << endl;
	cout << __LINE__ << endl;
	cout << ph->_i << " " << typeid(ph).name() << endl;
	cout << __LINE__ << endl;
	
	*pi = 2;
	// 这一块共享内存
	// 输出：
	// 2
	// 2
	cout << *pi << endl;
	cout << ph->_i << endl;

	cout << __LINE__ <<endl;
	delete ph;
	cout << __LINE__ << endl;
	
	cout << *pi << endl;
	
	return 0;
/*
4 4.396
a c
a Pc
618475361 Pi
33
Hehe
35
37
1 Pi
39
1 P4Hehe
41
2
2
51
~Hehe
53
0
*/	
}
