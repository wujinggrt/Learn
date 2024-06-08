#include <stdio.h>

void func1() {
	printf("I'm in func1\n");
	int j = 12;
	printf("j is %d\n", j);
}

int main(int argc, char** argv) {
	printf("argc is %d\n", argc);
	func1();
	int i = 0;
	printf("i is %d\n", i);
	i++;
	printf("Now i is %d\n", i);
	return 0;
}
