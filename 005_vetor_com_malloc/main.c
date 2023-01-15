#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(void) {
    int *vet, i;
    
    vet = (int*)malloc(N * sizeof(int));
    
    for (i = 0; i < N; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    for (i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    
    return 0;
}