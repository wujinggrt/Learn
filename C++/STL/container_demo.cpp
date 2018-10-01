#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    unordered_multiset<int> uiset = {4, 1, 1, 1, 7, 5, 4, 2, 3};
    cout << "unoredered_set:";
    for (const auto &e: uiset)
    {
        cout << e << " ";
    }
    cout << endl;
    // unoredered_set:3 2 5 7 1 1 1 4 4

    cout << "buket_count:" << uiset.bucket_count() << endl;
    // buket_count:11

    cout << "buket index:" << endl;
    for(const auto &e: uiset)
    {
        cout << e << " : " << uiset.bucket(e) << endl;;
    }
    // buket index:
    // 3 : 3
    // 2 : 2
    // 5 : 5
    // 7 : 7
    // 1 : 1
    // 1 : 1
    // 1 : 1
    // 4 : 4
    // 4 : 4

    cout << "uiset.bucket_size(1):" << uiset.bucket_size(1) << endl;
    auto it = uiset.begin(1);
    while (it != uiset.end(1))
    {
        cout << *it << endl;
        ++it;
    }
    // uiset.bucket_size(1):3
    // 1
    // 1
    // 1
    return 0;
}