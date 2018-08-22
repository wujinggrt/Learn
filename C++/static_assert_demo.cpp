#include <iostream>
using namespace std;

int main() {

    static_assert(true, "true");
    static_assert(false, "false");
    static_assert(('c' == 'C'), "lowercase and uppercase");

    return 0;
}