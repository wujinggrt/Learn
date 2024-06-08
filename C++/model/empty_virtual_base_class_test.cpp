#include <cstdio>

class X {};

class Y : public virtual X {};

class Z : public virtual X {};

class A : public Y, public Z {};

int main() {
	X x;
	Y y;
	A a;
	// clang++, x64
	// print 1
	printf("sizeof(X):%lu\n", sizeof(x));
	// 8
	printf("sizeof(Y):%lu\n", sizeof(y));
	// 16
	printf("sizeof(A):%lu\n", sizeof(a));
	return 0;
}
