#include <memory>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

void test()
{
        unordered_multiset<int> uiset = {4, 1, 1, 1, 7, 5, 4, 2, 3};
    cout << "size():" << uiset.size() << '\n';
// size():9
    cout << "max_size():" << uiset.max_size() << '\n';
// max_size():1152921504606846975
    cout << "buket_count():" << uiset.bucket_count() << endl;
// buket_count():11
    cout << "max_bucket_count():" << uiset.max_bucket_count() << '\n';
// max_bucket_count():1152921504606846975
    cout << "bucket(1):" << uiset.bucket(1) << '\n';
// bucket(1):1
    // not exist in uiset
    cout << "bucket(6):" << uiset.bucket(6) << '\n';
// bucket(6):6
    cout << "find(4):" << *uiset.find(4) << '\n';
// find(4):4
    cout << "load_factor():" << uiset.load_factor() << '\n';
// load_factor():0.818182
    cout << "max_load_factor():" << uiset.max_load_factor() << '\n';
// max_load_factor():1
    cout << "unoredered_set:";
    for (const auto &e: uiset)
    {
        cout << e << " ";
    }
    cout << endl;
// unoredered_set:3 2 5 7 1 1 1 4 4


    for (auto it_bucket = uiset.cbegin(); it_bucket != uiset.cend(); ++it_bucket)
    {
        cout << *it_bucket << '\n';
    }
// 3
// 2
// 5
// 7
// 1
// 1
// 1
// 4
// 4

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

    // traverse bucket
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

    cout << "uiset.bucket_size(4):" << uiset.bucket_size(4) << endl;
    it = uiset.begin(4);
    while (it != uiset.end(4))
    {
        cout << *it << endl;
        ++it;
    }
// uiset.bucket_size(4):2
// 4
// 4

    cout << "uiset.bucket_size(7):" << uiset.bucket_size(7) << endl;
    it = uiset.begin(7);
    while (it != uiset.end(7))
    {
        cout << *it << endl;
        ++it;
    }
// uiset.bucket_size(7):1
// 7

    cout << "uiset.bucket_size(6):" << uiset.bucket_size(6) << endl;
    it = uiset.begin(6);
    while (it != uiset.end(6))
    {
        cout << *it << endl;
        ++it;
    }
// uiset.bucket_size(6):0

}

int main()
{
    std::unordered_map<std::string, int> m{{"H", 2}, {"A", 1}};
    if (m["B"])
    {
        cout << m["B"] << '\n';
    }
    else
    {
        cout << "not exist" << '\n';
    }
    for (auto e: m)
    {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}