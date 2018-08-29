#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// 不超过1000的整数
	vector<int> num;
	num.reserve(999);
	// 读取数值
	string temp; 
	int divisor;

	cin >> temp >> divisor;
	for (const auto &c: temp)
	{
		num.push_back(c - '0');
	}
	// 原始的除法
	// stoi
	string result = "";
	auto it = num.cbegin();

	// 除数中的余数
	int remainder = 0;
	for(; it != num.cend(); ++it)
	{
		remainder = *it + remainder * 10;
		// 这儿不能写num.cend()，因为会有it在end-1的时候没有考虑到，
		// 执行++it, boom
		while (remainder < divisor && it != num.cend() - 1)
		{
			++it;
			remainder = remainder * 10 + *it;
			result += to_string(0);
		}
		result += to_string(remainder / divisor);
		remainder = remainder % divisor;
	}
	auto it_s = result.begin();
	// result.size()是1说明为0或者。。。
	for (; it_s != result.end() && *it_s == '0' && result.size() > 1; ++it_s)
	{ 
	}
	result.erase(result.begin(), it_s);
	cout << result << " " << remainder << endl;

    return 0;
}