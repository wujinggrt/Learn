#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec = {4, 12, 5, 8, 1, 7, 2};
    make_heap(ivec.begin(), ivec.end());
    cout << "make:";
    for(const auto &e : ivec)
    {
        cout << e << " ";
    }
    cout << endl;

    sort_heap(ivec.begin(), ivec.end());
    ivec.push_back(23);
    push_heap(ivec.begin(), ivec.end());
    for(const auto &e : ivec)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}