#include <stdio.h>

void troca(int *pa, int *pb) {
    int temp;
    temp = (*pa);
    *pa = *pb;
    *pb = temp;
}

int main(void) {
    int a = 1, b = 2;

    printf("a: %d; b: %d\n", a, b);
    troca(&a, &b);
    printf("a: %d; b: %d\n", a, b);
}