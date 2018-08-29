#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cout << ('a' < 'b') <<endl;
    map<int, int> m;
    m[0] = 3;
    m[1] = 2;
    m[45] = 4;
    for(auto &e: m)
    {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}