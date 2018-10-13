#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 还是应该用for (int i = 0; i < s.size().....)
// 这样的话只用在s里面判断
bool Check(const string s)
{
    int p_count = 0;
    int a_count = 0;
    int t_count = 0;

    // P之前、中、T后
    string a;
    string b;
    string c;
    // aPbATca是输入的字符串，需要先判断aPbTc是否正确，弱OK，则OK
    // 比如APAAATAA, b is AA, so that aPbTc is APAATAA, clearly incorrect.
    for (auto e : s)
    {
        switch(e)
        {
            case 'P':
                p_count++;
                break;
            case 'A':
                a_count++;
                break;
            case 'T':
                t_count++;
                break;
            default:
                return false;
                break;
        }// switch

        // P之前的字符串
        if (!p_count)
        {
            a += e;
        }
        // P,T中间的字符串
        else if (!t_count && e != 'P')
        {
            b += e;
        }
        // T之后的字符串
        else if (e != 'T' && e != 'P')
        {
            c += e;
        }// else
    }// for 
    
    // check PAT word count
    if (p_count != 1 || b == "" || t_count != 1)
    {
        return false;
    }
    // check xPATx,注意，x是空格，很容易被忽略
    if (a.size() * b.size() == c.size()) 
    {
        return true;
    }
    // check  aPbTc, 需要a等于c，因为xPATx
    // aPbATca, 所以这儿ca就是两倍a
    // if (b == "AA" && a.size() * 2 == c.size())
    // {
    //     return true;
    // }
    
    return false;
}// Check()

void DemandPass()
{
    int n;
    cin >> n;
    // 读掉回车符
    cin.get();
    vector<string> svec;
    svec.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        string temp;
        getline(cin, temp);
        svec.push_back(temp);
    }// for

    for (auto s : svec)
    {
        cout << (Check(s) ? "YES" : "NO") << endl;
    }
}

int main()
{
    DemandPass();
    return 0;
}