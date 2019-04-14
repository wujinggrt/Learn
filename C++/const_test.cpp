#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A(int i = 0) : i_{i} { 
        printf("%d %s\n", i_, __func__);
    }
    ~A() {
        printf("%d %s\n", i_, __func__);
    }

    A(const A &a) : A(a.i_) {
        printf("delegated!\n");
    }

    A(const A &&a) : A(a.i_) {
        printf("moving\n");
    }
    A& operator=(const A &&a) {
        printf("moving =====\n");
        i_ = a.i_;
        return *this;
    }

private:
    int i_;
};

int main() {
    int i = 50;
    int *const p = &i;
    *p = 4;
    printf("%d %d\n", i, *p);
}