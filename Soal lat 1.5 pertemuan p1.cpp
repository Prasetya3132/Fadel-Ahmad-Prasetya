#include <stdio.h>

int main() {
    int A, B, temp;

    printf("Masukkan dua bilangan bulat (A dan B): ");
    scanf("%d %d", &A, &B);

    temp = A;
    A = B;
    B = temp;

    printf("Setelah ditukar:\n");
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    return 0;
}

