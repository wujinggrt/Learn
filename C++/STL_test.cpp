#include <iostream>
#include <vector>
using namespace std;

#define PRINT_VEC(vec) do{\
cout << "PRINT_VEC called:" << endl; \
for(const auto &__e : vec) \
{ \
    cout << __e << " "; \
} \ 
cout << endl; \
} while(0);


int main()
{
    vector<int> vec;
    vec.reserve(10);
    for(int i = 0;i < 10; ++i)
    {
        vec.push_back(i);
    }
    vec.erase(vec.begin() + 4, vec.begin() + 5);
    PRINT_VEC(vec);
    vec.insert(vec.begin() + 2, 2, -1);
    PRINT_VEC(vec);

    return 0;
}