#include <iostream>
using namespace std;

class B {
	public:
	~B() {
			cout << __func__ << endl;
		}
};

class D : public B {
	public:
		~D() { cout << __func__ << endl;
		}
};

int main() {
	D b;
	return 0;
}
