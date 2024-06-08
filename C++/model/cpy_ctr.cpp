#include <iostream>
using namespace std;

class Hehe{
	public:
		Hehe() :i(0) {cout << "ctr" << endl;}
		Hehe(const Hehe& h) {
			cout << "cpy" << endl;
			this->i = h.i;
		}

		int i;
};

int main() {
	Hehe h = Hehe();
	Hehe i = h;
	Hehe j = Hehe(h);
	Hehe k(h);
	return 0;
}
