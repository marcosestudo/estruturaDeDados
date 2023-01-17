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

void profundidade(TNoA *a) {
    if (a != NULL) {
        printf("%c\n", a->info);
        profundidade(a->esq);
        profundidade(a->dir);
    }
}

void simetrica(TNoA *a) {
    if (a != NULL) {
        simetrica(a->esq);
        printf("%c\n", a->info);
        simetrica(a->dir);
    }
}

void posOrdem(TNoA *a) {
    if (a != NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n", a->info);
    }
}

void imprime(TNoA *no, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (no != NULL) {
        printf(" %c\n", no->info);
        imprime(no->esq, tab + 4);
        printf("\n");
        imprime(no->dir, tab + 4);
    } else {
        printf(" Vazio");
    }
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
    
    return 0;
}