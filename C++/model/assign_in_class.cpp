#include <iostream>
using namespace std;

class Hehe {
public:
	Hehe() : Hehe(45) {}
	Hehe(int i) : _i(i) {
		cout << _i << endl;
	}

	int _i = 4;
};

class Temp {
public:
	Temp() : Temp(2) {}
	Temp(int i) {
		cout << _i << endl;
		_i = i;
		cout << _i << endl;
	}

	int _i = 10;
};

int main() {
	Hehe h;
	// 45
	// 45
	cout << h._i << endl;
	// 10
	// 2
	// 说明_i = 4先执行。
	Temp t;
	return 0;
}
