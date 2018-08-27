#include <iostream>
#include <initializer_list>
using namespace std;

template<typename T>
class Hehe
{
public:
    Hehe(initializer_list<T> il)
    {
        cout << "constructed with il(" << il.size() << " elements)" << endl;
        for (const auto &e : il)
        {
            cout << e << endl;
        }
    }
};

int main()
{
    Hehe<int> h = { 1, 2, 3, 4, 5};
/*
constructed with il(5 elements)
1
2
3
4
5
*/
    return 0;
}