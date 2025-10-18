#include <stdio.h>

int main() {
    int x[15];
    printf("Alamat x[3] = %p\n", (void*)&x[3]);
    printf("Alamat x[9] = %p\n", (void*)&x[9]);
    return 0;
}

