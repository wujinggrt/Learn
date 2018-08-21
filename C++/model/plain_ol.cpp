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
	return 0;
}

