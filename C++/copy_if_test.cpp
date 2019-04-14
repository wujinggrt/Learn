#include <iterator>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 0);
    vector<int> dst(10);
    copy(vec.begin(), vec.end(), dst.begin());
    for (auto e: dst) {
        cout << e << " ";
    }
    std::copy(dst.begin(), dst.end(),
            std::ostream_iterator<int>(std::cout, " "));
    cout << "\n";
}