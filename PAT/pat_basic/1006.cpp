#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FormatOutput()
{
    int num;
    cin >> num;
    vector<string> svec;
    svec.reserve(27);
    string temp;
    int part = num % 10;
    for (int i = 0; i < part; ++i)
    {
        temp += '1' + i;
    }// for
    svec.push_back(temp);
    temp = "";
    if (num /= 10)
    {
        part = num % 10;
        for (int i = 0; i < part; ++i)
        {
            temp += "S";
        }
    }
    svec.push_back(temp);
    temp = "";
    if (num /= 10)
    {
        part = num % 10;
        for (int i = 0; i < part; ++i)
        {
            temp += "B";
        }
    }
    svec.push_back(temp);
    auto crit = svec.crbegin();
    string result;
    while (crit != svec.crend())
    {
        result += *crit++;
    }
    cout << result;
}

int main()
{
    FormatOutput();
    return 0;
}
