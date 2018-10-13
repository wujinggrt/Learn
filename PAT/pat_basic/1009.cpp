#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    istringstream is(s);
    stack<string, vector<string>> st;
    while (is >> s)
    {
        st.push(s);
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
        if (!st.empty())
        {
            cout << " ";
        }
    }
    return 0;
}