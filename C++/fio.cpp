#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void cpp_test()
{
    fstream  input("./hehe.txt");
    string s;
    while (input >> s)
    {
        cout << s << " ";
    }
    cout << endl;
}


void test()
{
    FILE *fid;
    fid = fopen("./hehe.txt", "r");
    if (!fid)
    {
        cerr << "false!\n";
        return;
    }
    char c;
    while (EOF != (c = getc(fid)))
    {
        printf("%c ", c);
    }
    printf("\n");
    fclose(fid);

    fid = fopen("./hehe.txt", "r");
    if (!fid)
    {
        cerr << "false!\n";
        return;
    }
    char s[1024];
    fgets(s, 1024, fid);
    {
        printf("%d\n", __LINE__);
        printf("%s\n", s);
    }
    fclose(fid);
}

int main()
{
    test();
    FILE *f = fopen("./write.dat", "wb");
    if (!f)
    {
        fprintf(stderr, "error\n");
        exit(0);
    }
    fprintf(f, "I write for test\nHehe");
    return 0;
}