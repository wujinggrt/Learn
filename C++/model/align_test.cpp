#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;

struct Empty {
};

struct BigData {
    char array[33];
};
 
struct Data {
    // 后面paded 33 + 3 = 36 % 4 = 0, 
    BigData bd;
    // padding 36 + 4 = 40 % 8 = 0
    int integer;
    // 40 + 48
    double d;
};
 
struct Data2 {
    // padding 33 + 7 = 40 % 8 = 0
    BigData bd;
    // 40 + 8 = 48
    double d;
};
 
int main() {
    // offset is macro
    // 可以看出，对齐值是struct/class中对齐值最大的哪一个
    printf("Alignof \n- Empty:%zu\n- int:%zu\n- int64_t:%zu\n- BigData:%zu\n- Data:%zu\n- Data2:%zu\n", 
        alignof(Empty), 
        alignof(int),
        alignof(int64_t),
        alignof(BigData), 
        alignof(Data), 
        alignof(Data2));
    
    printf("\nSize:\n- sizeof(BigData):%zu\n- sizeof(Data):%zu\n- sizeof(Data2):%zu\n", sizeof(BigData), sizeof(Data), sizeof(Data2));
    cout << "\nstruct Data:\n";
    printf("Offset of \n- bd:%zu \n- integer:%zu \n- d:%zu\n", offsetof(Data, bd), offsetof(Data, integer), offsetof(Data, d));
    // alignof operator

    cout << "\nstruct Data2:\n";
    printf("Offset of\n- bd:%zu\n- d:%zu\n", offsetof(Data2, bd), offsetof(Data2, d));
}