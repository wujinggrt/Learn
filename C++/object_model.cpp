#include <iostream>
#include <cstdio>
using namespace std;

class Hehe {
public:
	static int i;
	float j;
	float d;
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
	//cout << "&(h.j) == (&h + (&Hehe::j - 1) : " << (&(h.j) == (&h + (&Hehe::j - 1))) << endl; 
	
	printf("&Hehe::j = %p\n", &Hehe::j);
	printf("&Hehe::d = %p\n", &Hehe::d);

	printf("&Hehe::j = %d\n", &Hehe::j);
	printf("&Hehe::d = %d\n", &Hehe::d);

	// 被当成bool，应该用printf
	cout << "&Hehe::j: " <<  &Hehe::j << endl;
	cout << "&Hehe::d: " << &Hehe::d << endl;
	
/*
int:4double: 8
sizeof(ptr): 8
sizeof(h.j): 4
sizeof h: 8
&Hehe::j = (nil)
&Hehe::d = 0x4
&Hehe::j = 0
&Hehe::d = 4
&Hehe::j: 1
&Hehe::d: 1
*/
	return 0;
}
