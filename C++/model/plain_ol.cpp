#include <iostream>
using namespace std;

typedef struct {
	float x, y, z;
} Point;

Point global;

void print_point(const Point &p) {
	cout << p.x << endl;
	cout << p.y << endl;
	cout << p.z << endl;
}

int main() {
	Point local;
	cout << "global:" << endl;
	print_point(global);
	cout << "local:" << endl;
	print_point(local);

/*
全局变量是初始化的，因为有__sti（对于存在default constructor而言）等因素
输出：
global:
0
0
0
local:
-5.85354e+20
4.59163e-41
0
*/

	return 0;
}

