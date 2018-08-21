#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";
    const string *pcs = &s;
    string *t = const_cast<string*>(pcs);
    (*t)[0] = 'Q';
    cout << *t << endl;
    //Qello
    const char * cp = "Hello world!";
    char *q = const_cast<char *>(cp);
    cout << q << endl;
    // 
    q[0] = 'Q';
    cout << q << endl;
// Hello world!
// Segmentation fault (core dumped)
// 未定义的。


    return 0;
}
