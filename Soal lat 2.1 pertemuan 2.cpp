#include <stdio.h>

int main() {
    char x[12];
    printf("Alamat x[0] = %p\n", (void*)&x[0]);
    printf("Alamat x[8] = %p\n", (void*)&x[8]);
    return 0;
}
