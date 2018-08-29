#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int judge(const char &lhs, const char &rhs)
{
    switch(lhs)
    {
        case 'C':
            return (rhs == 'J' ? 
                1 : 
                (rhs == 'C' ? 0 : -1 ));
            break;
        case 'B':
            return (rhs == 'C' ?
                1 :
                (rhs == 'B' ? 0 : -1));
            break;
        case 'J':
            return (rhs == 'B' ? 
                1 :
                (rhs == 'J' ? 0 : -1));
            break;
        default:
            break;
    }
    return -2;
}


int main()
{
    int count;
    cin >> count;
    vector<char> first;
    vector<char> second;
    for (int i = 0; i < count; ++i)
    {
        char f;
        char s;
        cin >> f >> s;
        first.push_back(f);
        second.push_back(s);
    }
    
    auto it_f = first.cbegin();
    auto it_s = second.cbegin();
    map<int, int> first_results;
    first_results[-1] = 0;
    first_results[0] = 0;
    first_results[1] = 0;
    map<char, int> first_win_records;
    first_win_records['J'] = 0;
    first_win_records['B'] = 0;
    first_win_records['C'] = 0;
    map<char, int> second_win_records;
    second_win_records['J'] = 0;
    second_win_records['B'] = 0;
    second_win_records['C'] = 0;
    
    while (it_f != first.cend() && it_s != second.cend())
    {
        auto result = judge(*it_f, *it_s);
        first_results[result]++;
        if (result == 1)
        {
            first_win_records[*it_f]++;
        }
        else if (result == -1)
        {
            second_win_records[*it_s]++;
        }
        else
        {
        }
        ++it_f;
        ++it_s;
    }
    
    // 甲的记录
    cout << first_results[1] << " "  << 
        first_results[0] << " " << 
        first_results[-1] << endl;
    // 乙
    cout << first_results[-1] << " "  << 
        first_results[0] << " " << 
        first_results[1] << endl;
    auto max_win = max({first_win_records['J'], first_win_records['B'], first_win_records['C']});
    count = 0;
    vector<char> key;
    for (auto &e: first_win_records)
    {
        if (e.second == max_win)
        {
            ++count;
            key.push_back(e.first);
        }
    }
    sort(key.begin(), key.end());
    cout << key.front() << " ";

    max_win =  max({second_win_records['J'], second_win_records['B'], second_win_records['C']});
    count = 0;
    key.clear();
    for (const auto &e: second_win_records)
    {
        if (e.second == max_win)
        {
            ++count;
            key.push_back(e.first);
        }
    }
    sort(key.begin(), key.end());
    cout << key.front() << endl;

    return 0;
}