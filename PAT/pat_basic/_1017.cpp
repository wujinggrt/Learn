#include <iostream>
using namespace std;

long long mode(long long a, long long b, long long mode)
{
	long long sum = 1;
	while (b) {
		if (b & 1) {
			sum = (sum * a) % mode;
			b--;
		}
		b /= 2;
		a = a * a % mode;
	}
	return sum;
}

int main()
{
    int dividend;
    int divisor;
    cin >>dividend >>divisor;

    auto mod = mode(dividend, divisor, ;
    cout << first << " " << (dividend - first) << endl;;

    return 0;
}