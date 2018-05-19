#include <iostream>
using namespace std;

void Callatz()
{
	int n;
	cin >> n;
	int count = 0;
	for(; n != 1; ++count)
	{
		// odd
		if (n % 2)
		{
			n = (3 * n + 1) / 2;
		}// if
		else // even
		{
			n /= 2;
		}// else
	}// for 
	cout << count;
}// Callatz

int main()
{
	Callatz();
	return 0;
}