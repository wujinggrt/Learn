#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long a, b, c;
    int count;
    vector<vector<long>> vec;
    cin >> count;
    vec.reserve(count);
    for (long i = 0; i < count; ++i)
    {
        cin >> a >> b  >> c;
        vec.push_back(vector<long>{a, b, c});
    }
    for(long i = 0; i < vec.size(); ++i)
    {
        cout << "Case #" 
            << i + 1
            << ": "
            << (((vec[i][0] + vec[i][1]) > vec[i][2]) ?
                "true" : "false")
            << endl;
    }

    return 0;
}