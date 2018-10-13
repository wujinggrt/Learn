#include <string>
#include <iostream>
#include <map>
using namespace std;

class Hehe
{
public:
    void operator[](string first)
    {
        cout << first << '\n';
    }
};

int main()
{
    Hehe h;
    h["as"];
    return 0;
}