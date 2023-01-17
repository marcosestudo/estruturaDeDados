#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 4);
        printf("\n");
        imprime(nodo->dir, tab + 4);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void simetrica(TNoA *nodo){
     if (nodo!= NULL){
          simetrica(nodo->esq);
          printf("%c ",nodo->info);
          simetrica(nodo->dir);
      }
}

void pos_ordem(TNoA *nodo){
     if (nodo!= NULL){
          pos_ordem(nodo->esq);
          pos_ordem(nodo->dir);
          printf("%c ",nodo->info);
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
    
    printf("\n");
    printf("Simetrica: ");
    simetrica(raiz);
    
    printf("\n");
    printf("Pós-ordem: ");
    pos_ordem(raiz);
};
