#include <iostream>
using namespace std;

int main() {
    int i = 5;
    auto l = [i] (const int _i) {
        return _i < i;
    };
    // 1
    cout << l(0) << endl;
    return 0;
}