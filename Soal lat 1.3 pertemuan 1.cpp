#include <stdio.h>

int main() {
    int skor;

    printf("Masukkan skor siswa (0-100): ");
    scanf("%d", &skor);

    if (skor == 100) {
        printf("Skor sempurna!\n");
    } else if (skor >= 90) {
        printf("Nilai: A\n");
    } else if (skor >= 80) {
        printf("Nilai: B\n");
    } else if (skor >= 70) {
        printf("Nilai: C\n");
    } else if (skor >= 60) {
        printf("Nilai: D\n");
    } else {
        printf("Nilai: F\n");
    }

    return 0;
}

