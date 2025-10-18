#include <stdio.h>

int main() {
    float lebar, tinggi;

    printf("Masukkan lebar dan tinggi persegi panjang: ");
    scanf("%f %f", &lebar, &tinggi);

    float luas = lebar * tinggi;
    float keliling = 2 * (lebar + tinggi);

    printf("Luas: %.2f\n", luas);
    printf("Keliling: %.2f\n", keliling);
    return 0;
}

