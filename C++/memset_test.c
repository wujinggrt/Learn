#include <stdio.h>
#include <string.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[5];
    printf("%d\n", sizeof b);
    // 16843009 的二进制为：‭0000 0001 0000 0001 0000 0001 0000 0001‬，每八位一个byte
    memset(b, 1, sizeof b);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n",b[i]);
    }
}