#include <vector>
#include <iostream>
using namespace std;

void shift()
{
    int n;
    cin >> n;
    vector<unsigned> vec;
    vec.reserve(n);
    int m;
    cin >> m;
    for (int i = 0; i < n; ++i)
    {
        unsigned tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    m = m % n;
    m = n - m;
    vector<unsigned> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        result.push_back(vec[m % n]);
        ++m;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
}

int main()
{
    shift();
    return 0;
}