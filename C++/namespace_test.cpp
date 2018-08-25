#include <iostream>
using namespace std;

namespace a
{
    int i = 10;
}

namespace b
{
    using namespace a;
    int j = 20;
    int k = i;
}

namespace b
{
    int i2 = a;
}

int main()
{
    using namespace b;
    cout << j << " " << k << endl;
    cout << i2;
    return 0;
}