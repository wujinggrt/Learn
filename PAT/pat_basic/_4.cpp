#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StuInfo
{
    string name;
    string no;
    int score;
};

void Rank()
{
    int n;
    cin >> n;
    vector<StuInfo> vec;
    for (int i = 0; i < n; ++i)
    {
        string name, no;
        int score;
        cin >> name >> no >> score;
        StuInfo si = {name, no, score};
        vec.push_back(si);
    }// for

    int max_score = 0;
    int max_i = 0;
    int min_score = 100;
    int min_i = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vec[i].score > max_score)
        {
            max_score = vec[i].score;
            max_i = i;
        }// if
        if (vec[i].score < min_score)
        {
            min_score = vec[i].score;
            min_i = i;
        }// if
    }// for
     
    cout << vec[max_i].name << " " << vec[max_i].no << endl;
    cout << vec[min_i].name << " " << vec[min_i].no << endl;
}

int main()
{
    Rank();
    return 0;
}