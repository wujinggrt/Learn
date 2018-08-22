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
a c
a Pc
97 Pi
26
Hehe
28
30
1 Pi
32
1 P4Hehe
34
2
2
44
~Hehe
46
0
*/	
}
