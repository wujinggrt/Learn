#include <iostream>
#include <generator>
#include <memory>
using namespace std;

struct Node {
	const int* const i_;
	Node(int* i) : i_{i} {}
};

int main() {
	auto* p = new int{3};
	Node n{p};
	cout << *n.i_ << "\n";
}
