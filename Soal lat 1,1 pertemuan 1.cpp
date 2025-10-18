#include <stdio.h>

int main() {
    int a;
    char b;
    float c;

    printf("Masukkan int, char, dan float (dipisahkan spasi): ");
    scanf("%d %c %f", &a, &b, &c);

    printf("%d\n", a);
    printf("%c\n", b);
    printf("%.2f\n", c); 
    return 0;
}

