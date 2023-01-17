#include <stdio.h>
#include <stdlib.h>

struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
};
typedef struct noA TNoA;

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');

    printf("Fim");
    return 0;
}