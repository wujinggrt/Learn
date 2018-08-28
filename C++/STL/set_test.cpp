#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> iset = {4, 1, 1, 7, 5, 4, 2, 3};
    cout << "iset:";
    for(auto &e: iset)
    {
        cout << e << " ";
    }
    cout << endl;
// iset:1 2 3 4 5 7
// 显然排好了序，因为底层是RB-tree

    multiset<int> miset = {4, 1, 1, 7, 5, 4, 2, 3};
    cout << "miset:";
    for(auto &e: miset)
    {
        cout << e << " ";
    }
    cout << endl;
// miset:1 1 2 3 4 4 5 7    

    auto it_4 = miset.lower_bound(4);
    auto it_4_end = miset.upper_bound(4);

    cout << "*it_4:" << *it_4 << endl;
    cout << "*it_4_end:" << *it_4_end << endl;
// *it_4:4
// *it_4_end:5
    return 0;
}