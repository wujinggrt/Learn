#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    unordered_map<int, int> m{{1, 2}, {3, 2}, {4, 4}};
    auto it = m.find(1);
    for (auto e: m) {
        printf("%d %d\n", e.first, e.second);
    }
}