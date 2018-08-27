#include <iostream>
using namespace std;

class Hehe
{
public:
    Hehe(int i = 1) : _i(i) {}
    int get_i() { cout << "get_i" << endl; return _i; }
    const int get_i() const { cout << "const get_i" << endl; return _i; }

private:
    int _i;
};

int main()
{
    Hehe h;
    const auto i = h.get_i();
    const Hehe hh;
    auto ii = hh.get_i();
// get_i
// const get_i
    return 0;
}