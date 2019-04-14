#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int g = 10;

class A {
public:
    explicit A(int i = 1) : i_{i} {
        printf("Default one!\n");
    }

    A(const A &other) : i_{other.i_} {
        printf("Copy\n");
    }

    A(A &&other) : i_{std::move(other.i_)} {
        printf("Move\n");
        other.i_ = 0;
    }

public:
    int i_;
};

class B {
public:
    B() {
        cout << __func__ << "\n";
    }
    explicit B(A a) : a_{a} {
        cout << __func__ << "\n";
    }

    B(const B &b) : a_{b.a_} {
        cout << "Copyyyy" << "\n";
    }

private:
    A a_;
};

int main()
{
    A a;
    cout << __LINE__ << "\n";
    A b = std::move(a);
    cout << __LINE__ << "\n";
    A c(b);
    cout << __LINE__ << "\n";
    A d(std::move(A()));
    cout << __LINE__ << "\n";

    B bb;
    cout << __LINE__ << "\n";
    B b1 = std::move(bb);
    cout << __LINE__ << "\n";

    auto a1 = A(2);
    cout << __LINE__ << "\n";
    vector<A> vec;
    vec.reserve(10);
    vec.push_back(a1);
    cout << __LINE__ << "\n";
    vec.push_back(std::move(b));
    cout << __LINE__ << "\n";
    vec.push_back(A{200});
    cout << __LINE__ << "\n";
    {
        A a;
        vec.push_back(move(a));
    }
    cout << __LINE__ << "\n";
    vec.reserve(100);
}