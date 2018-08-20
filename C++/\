#include <iostream>
#include <cstdio>
using namespace std;

class Hehe {
public:
	static int i;
	int j;
	double d;
};

int main() {
	Hehe h;
	Hehe *ph = &h;
	int t = 0;
	double d = 0.0;
	cout << "int:" << sizeof(t) << "double: " << sizeof(d) << endl;
	cout << "sizeof(ptr): " << sizeof(ph) << endl;
	cout << "sizeof(h.j): " << sizeof(h.j) << endl;
	cout << "sizeof h: " << sizeof(h) << endl;
	
	printf("&Hehe::j = %p\n", *(&Hehe::j));
	printf("&Hehe::d = %p\n", *(&Hehe::d));


	cout << "&Hehe::j: " <<  &Hehe::j << endl;
	cout << "&Hehe::d: " << &Hehe::d << endl;
	return 0;
}
