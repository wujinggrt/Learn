#include <sstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int cnt = 0;
    int first;
    int second;
    vector<pair<int, int>> vec;
    vec.reserve(20);
    string s;
    getline(cin, s);
    istringstream is(s);
    while (is >> first >> second)
    {
        if (!second)
        {
            continue;
        }
        first = first * second;
        --second;
        vec.push_back({first, second});
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i].first << 
            " " << 
            vec[i].second << 
            (i != vec.size() - 1 ? " " : "");
    }
    // 零多项式
    if (vec.empty())
    {
        cout << "0 0";
    }
    return 0;
}