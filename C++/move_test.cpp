#include <iostream>
#include <utility>
using namespace std;

int g = 10;

int main()
{
    int i = 1;

    cout << "g:" << g << endl;
    cout << "i:" << i << endl;

    int &&j = std::move(g);
    int &&k = std::move(i);

    cout << "&&j:" << j << endl;
    cout << "&&k:" << k << endl;
    cout << "g:" << g << endl;
    cout << "i:" << i << endl;

    i = 2;
    j = 3;
    cout << "i:" << i << endl;
    cout << "&&j:" << j << endl;

    string s = "Hello";
    cout << "s:" << s << endl;
    string &&t = std::move(s);
    cout << "&&t:" << t << endl;
    cout << "s:" << s << endl;

    s = "None";
    cout << "s:" << s << endl;
    
    t = "World";
    cout << "&&t:" << t << endl;

    return 0;
}