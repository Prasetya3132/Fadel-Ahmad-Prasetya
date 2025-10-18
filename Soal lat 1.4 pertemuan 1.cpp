#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2;

    printf("Masukkan koordinat titik A (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Masukkan koordinat titik B (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    float jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("Jarak antara A dan B: %.2f\n", jarak);
    return 0;
}

