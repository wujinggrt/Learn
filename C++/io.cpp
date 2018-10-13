#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include <cstdio>
using namespace std;

void test()
{
    fstream in("./input.txt", ios::in);
    fstream out("./output.txt", ios::out);
    int n;
    string s;
    while(getline(in, s))
    {
        cout << s << '\n';
        out << s << '\n';
    }
    in.close();
    out.close();
}

void c_test()
{
    FILE *f;
    f = fopen("./input.txt", "r");
    FILE *out;
    out = fopen("./output.txt", "w");
    char *s = (char *)malloc(1024 * sizeof *s);
    while (!feof(f))
    {
        fgets(s, 1024, f);
        printf("%s", s);
        fputs(s, out);
    }
    fclose(f);
    fclose(out);
}

int main()
{
    c_test();
    
    return 0;
}