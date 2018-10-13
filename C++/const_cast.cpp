#include <iostream>
using namespace std;

int main()
{
    const int i = 0;
    const int &ri = i;
    int &ri2 = const_cast<int &>(ri);
    ri2 = 1;
    cout << i << endl;
    cout << ri << endl;
    cout << ri2 << endl;

    int *ri3 = const_cast<int *>(&i);
    *ri3 = 10;
    cout << *ri3 << endl;
    cout << i << endl;

    const int *pi = &i;
    int *p = const_cast<int *>(pi);
    *p = 10;
    cout << *p << endl;
    cout << i << endl;

/*
0
1
1
10
0
10
0
*/

    int j = 1;
    const int *pj = &j;
    int *pj2 = const_cast<int *>(pj);
    *pj2 = 111;
    cout << *pj2 << endl;
    cout << j << endl;
/*
111
111
*/
    return 0;
}