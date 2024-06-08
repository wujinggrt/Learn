#include <iostream>
using namespace std;

long long QuickMode(long long a, long long b, long long mode)
{
    long long sum = 1;
    while (b)
    {
        if (b & 1)
        {
            sum = (sum * a) % mode;
            --b;
        }// if 
        b /= 2;
        a = a * a % mode;
    }// while
    return sum;
}// QuickMode

/*
long long Mode(long long a, long long b, long long mode)  
{  
    long long sum = 1;  
    a = a % mode;  
  
    while (b > 0) {  
        if (b % 2 == 1)     //判断是否是奇数，是奇数的话将多出来的数事先乘如sum  
            sum = (sum * a) % mode;  
  
        b /= 2;  
        a = (a * a) % mode;// 不断的两两合并再取模，减小a和b的规模  
    }  
    return sum;  
}  
*/

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (QuickMode(a, b, 1007)) << endl;
    return 0;
}