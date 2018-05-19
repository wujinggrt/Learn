#include <vector>
#include <iostream>
#include <string>
using namespace std;

void Write()
{
	string s;
	cin >> s;
	int sum = 0;
	for (auto c : s)
	{
		sum += c - '0';
	}
	
	vector<string> svec;
	svec.reserve(10);
	while(sum)
	{
		int temp = sum % 10;
		switch(temp)
		{
		case 1:
			svec.push_back("yi");
			break;
		case 2:
			svec.push_back("er");
			break;
		case 3:
			svec.push_back("san");
			break;
		case 4:
			svec.push_back("si");
			break;	
		case 5:
			svec.push_back("wu");
			break;	
		case 6:
			svec.push_back("LIU");
			break;	
		case 7:
			svec.push_back("qi");
			break;
		case 8:
			svec.push_back("ba");
			break;
		case 9:
			svec.push_back("jiu");
			break;			
		case 0:
			svec.push_back("ling");
			break;	
		default:
			break;
		}// switch
		sum /= 10;
	}// while
	string output_;
	for (int i = svec.size() - 1; i >= 0; --i)
	{
		output_ += svec[i] + (i == 0 ? string("") : string(" "));
	}
	cout << output_;
}// Write

int main()
{
	Write();
}