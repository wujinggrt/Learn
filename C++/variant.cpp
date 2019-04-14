#include <variant>
#include <string>
#include <iostream>
using namespace std;

int main() {
    std::variant<int, double> v = 1;
    int i = std::get<0>(v);
    cout << i << "\n";
}