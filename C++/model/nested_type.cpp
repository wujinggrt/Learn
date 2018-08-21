#include <iostream>
using namespace std;

typedef int length;

class Hehe {
	// typedef声明在这OK，可以编译
	// 防御式编程
	typedef float length;
public:
	void mumble(length val) { _val = val;}
	length mumble() {return _val;}

private:
	// 声明在这儿的话member function使用的事global的typedef
	//  typedef float length;
	// 应该放在class起始处
	length _val;
};

int main() {
	Hehe h;
	h.mumble(1.1);
	cout << h.mumble() << endl;
	return 0;
}
