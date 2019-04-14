#include <memory>
#include <iostream>
using namespace std;

int main()
{
    int i = 111;
    auto sp = make_shared<int>(34);
    cout << *sp << endl;
    shared_ptr<int> s(&i);
    cout << *s << endl;
    return 0;

}