#include <stdio.h>

#define N 3

void incrementa_vetor(int n, int *vet)  {
    int i;
    for (i = 0; i < n; i++) {
        vet[i]++;
    }
}

int main(void) {
    int vet[] = {1, 2, 3}, i;

    for (i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }

    incrementa_vetor(N, vet);

    printf("\n");
    
    for (i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    
    return 0;
}