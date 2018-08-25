#include <iostream>
#include <vector>
using namespace std;

#include "include_test.h"

int main() 
{
    vector<int> vec;
    vec.reserve(10);
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    for(auto e: vec)
    {
        cout << e << endl;
    }
    Test<int> t(vec);
    auto temp = t.get_vec();
    for(const auto &e: temp)
    {
        cout << e << endl;
    }

    return 0;
}