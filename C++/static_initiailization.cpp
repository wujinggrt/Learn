#include <iostream>
using namespace std;

class Hehe{
public:
	Hehe() {
		cout << __func__ << endl;
	}
};

Hehe global;

int main() {
	cout << __LINE__ << endl;
	Hehe h = global;
	cout << __LINE__ << endl;
	return 0;
}
