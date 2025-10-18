#include <stdio.h>

int main() {
    int x[2][3][5];
    printf("Alamat x[1][1][4] = %p\n", (void*)&x[1][1][4]);
    printf("Alamat x[0][0][3] = %p\n", (void*)&x[0][0][3]);
    return 0;
}

