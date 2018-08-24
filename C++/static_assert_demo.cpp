#include <iostream>
using namespace std;

int main() {

    static_assert(true, "true");
    static_assert(false, "false");
    static_assert(('c' == 'C'), "lowercase and uppercase");
/*
C++/static_assert_demo.cpp:7:5: error: static_assert failed "false"
    static_assert(false, "false");
    ^             ~~~~~
C++/static_assert_demo.cpp:8:5: error: static_assert failed "lowercase and uppercase"
    static_assert(('c' == 'C'), "lowercase and uppercase");
    ^             ~~~~~~~~~~~~
2 errors generated.
*/
    return 0;
}