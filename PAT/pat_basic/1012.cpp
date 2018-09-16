#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

template<typename T>
void print_N(T a, string sep = " ")
{
    if (!a)
    {
        cout << "N";
    }
    else
    {
        cout << a;
    }
    cout << sep;
}

int main()
{
    int n;
    cin >> n;
    vector<int> src;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        src.push_back(temp);
    }
    auto a1 = accumulate(src.begin(), src.end(), 0, 
        [] (int lhs, int rhs) {
            if (!(rhs % 5) && !(rhs % 2))
            {
                lhs += rhs;
            }
            return lhs;
        });
    bool a2_flag = true;
    auto a2 = accumulate(src.begin(), src.end(), 0,
        [&a2_flag] (int lhs, int rhs) {
            if (rhs % 5 == 1)
            {
                lhs = (a2_flag ? lhs + rhs : lhs - rhs);
                a2_flag = !a2_flag;
            }
            return lhs;
        });
    auto a3 = accumulate(src.begin(), src.end(), 0,
        [] (int lhs, int rhs){
            if (rhs % 5 == 2)
            {
                ++lhs;
            }
            return lhs;
        });
    int a4_count = 0;
    auto a4 = accumulate(src.begin(), src.end(), 0.0, 
        [&a4_count] (int lhs, int rhs) {
            if (rhs % 5 == 3)
            {
                lhs += rhs;
                ++a4_count;
            }            
            return lhs;
        });
    auto a4_result = (a4_count == 0 ? 0.0 : static_cast<double>(a4) / static_cast<double>(a4_count));
    auto a5 = accumulate(src.begin(), src.end(), 0, 
        [] (int lhs, int rhs) {
            if (rhs % 5 == 4 && rhs > lhs)
            {
                lhs = rhs;
            }
            return lhs;
        });

    print_N(a1);
    print_N(a2);
    print_N(a3);
    printf("%.1f ", a4_result);
    print_N(a5, "\n");

    return 0;
}