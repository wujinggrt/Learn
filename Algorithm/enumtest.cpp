#include <iostream>
using namespace std;

enum class Hehe
{
    Aa,
    Bb
};

int main()
{
    string h;
    cin >> h;
    cout << (h == Aa ? 'A' : 'B');
    return 0;
}