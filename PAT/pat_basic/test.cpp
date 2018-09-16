#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    cout << "(3.3 / 2):" << (3.3 / 2) << endl;
    cout << "(3 / 2):" << (3 / 2) << endl;
    cout << "(3.0 / 2):" << (3.0 / 2) << endl;
    cout << "(3 / 2.0):" << (3 / 2.0) << endl;
// (3.3 / 2):1.65
// (3 / 2):1
// (3.0 / 2):1.5
// (3 / 2.0):1.5
    return 0;
}