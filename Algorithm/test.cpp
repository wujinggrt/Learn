
#include <string>
#include <iostream>
using namespace std;

template <typename T>
struct Hehe
{
    T data;
};

template <typename T>
using HeheArray = Hehe<T>[3];

int main()
{
    string s;
    s = "haha";
    cout << s;
    return 0;
}