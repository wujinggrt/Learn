#include <iostream>
#include <cassert>
using namespace std;

int main() {
	assert(1 == 2);
	cout << __LINE__ << endl;
	return 0;
}