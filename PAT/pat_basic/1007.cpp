#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(unsigned n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    unsigned bound = sqrt(n) + 1;
    for (int i = 2; i < bound; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int prime_conjecture(unsigned n)
{
    if (n <= 3)
    {
        return 0;
    }
    vector<int> vec;
    vec.reserve(n / 2 + 1);
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (is_prime(i))
        {
            if (vec.size())
            {
                if (i - vec.back() == 2)
                {
                    ++count;
                }
            }
            vec.push_back(i);
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;   
    n = prime_conjecture(n);
    cout << n;
    return 0;
}