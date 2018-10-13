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
    if (a == 0)
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
    src.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        src.push_back(temp);
    }
    int a1 = accumulate(src.begin(), src.end(), 0, 
        [] (int lhs, int rhs) {
            if (!(rhs % 5) && !(rhs %2))
            {
                lhs += rhs;
            }
            return lhs;
        });
    bool a2_flag = true;
    int a2_count = 0;
    int a2 = accumulate(src.begin(), src.end(), 0,
        [&a2_flag, &a2_count] (int lhs, int rhs) {
            if (rhs % 5 == 1)
            {
                lhs = (a2_flag ? lhs + rhs : lhs - rhs);
                a2_flag = !a2_flag;
                ++a2_count;
            }
            return lhs;
        });
    int a3 = accumulate(src.begin(), src.end(), 0,
        [] (int lhs, int rhs){
            if (rhs % 5 == 2)
            {
                ++lhs;
            }
            return lhs;
        });
    int a4_count = 0;
    double a4 = accumulate(src.begin(), src.end(), 0.0, 
        [&a4_count] (int lhs, int rhs) {
            if (rhs % 5 == 3)
            {
                lhs += rhs;
                ++a4_count;
            }            
            return lhs;
        });
    auto a4_result = (a4_count == 0 ? 0.0 : a4 / a4_count);
    // 应该使用浮点数？
    int a5 = accumulate(src.begin(), src.end(), 0, 
        [] (int lhs, int rhs) {
            if (rhs % 5 == 4 && rhs > lhs)
            {
                lhs = rhs;
            }
            return lhs;
        });

    print_N(a1);
    if (a2_count)
    {
        printf("%d ", a2);
    }
    else
    {
        printf("N ");
    }
    print_N(a3);
    if (a4_count)
    {
        printf("%.1lf ", a4_result);
    }
    else
    {
        printf("N ");
    }
    print_N(a5, "");

    return 0;
}