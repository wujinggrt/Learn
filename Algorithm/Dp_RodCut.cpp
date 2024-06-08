#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 0 represant none
const int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int MemorizedCutRodAux(const int price[], int n, int revenue[]);

int MemorizeCutRod(const int price[], int n)
{
	// 0 to n, that is this array contains n + 1 elements.
	auto revenue = new int [n + 1];
	for (int i = 0; i < n + 1; ++i)
	{
		revenue[i] = INT_MIN;
	}
	auto ret = MemorizedCutRodAux(price, n, revenue);
	delete [] revenue;
	return ret;
}

int MemorizedCutRodAux(const int price[], int n, int revenue[])
{
	if (revenue[n] >= 0)
	{
		return revenue[n];
	}// if 
	int q;
	if (n ==0)
	{
		q = 0;
	}// if 
	else
	{
		q = INT_MIN;
		for (int i = 1; i <= n; ++i)
		{
			int temp = price[i] + MemorizedCutRodAux(price, n - i, revenue);;
			if (q < temp)
			{
				q = temp;
			}// if
		}// for
	}// else
	revenue[n] = q;
	return q;
}// MemorizedCutRodAux

// a bottom up solution
int BottomUpCutRod(const int price[], const int n)
{
	vector<int> revenue(32, INT_MIN);
	revenue.reserve(n + 1);
	revenue[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		int max_temp = INT_MIN;
		for (int j = 1; j <= i; ++j)
		{
			auto val = price[j] + revenue[i - j];
			if (max_temp < val)
			{
				max_temp = val;
			}// if
		}// for
		revenue[i] = max_temp;
	}// for
	return revenue[n];
}

int main()
{
	int i;
	cin >> i;
	// auto t = MemorizeCutRod(price, i);
	auto t = BottomUpCutRod(price, i);
	cout << t;
	return 0;
}