#include <iostream>
using namespace std;

namespace wj
{
    class A;

    class A
    {
        public:
        
    }
}

class A
{
public:
    explicit A(int i = 10) :
        _i{i},
        ui{new wj::A}
        {
            cout << __func__ << endl;
        }

private:
    int _i;
    wj::A *ui;
};

int main()
{
    A a;
    cout << __LINE__ << endl;
    return 0;
}