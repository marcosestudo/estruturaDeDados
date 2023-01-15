#include <stdio.h>

#define N 3

float media(int n, int *vet) {
    int i;
    float soma = 0.0;
    for (i = 0; i < N; i++) {
        soma += vet[i];
    }
    return soma / N;
}

int main(void) {
    int vet[N], i;

    for (i = 0; i < N; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("Media: %.2f", media(N, vet));
    
    
    return 0;
}