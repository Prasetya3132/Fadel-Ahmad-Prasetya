#include <stdio.h>

int main() {
    long x[12][14];
    printf("Alamat x[0][0] = %p\n", (void*)&x[0][0]);
    printf("Alamat x[2][4] = %p\n", (void*)&x[2][4]);
    return 0;
}

