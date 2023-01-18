#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    char info;
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA* busca(TNoA *no, int chave) {
    // recebe endereço da raiz e chave procurada
    while (no != NULL) {
        if (no->chave == chave) {
            return no; // achou, retorna o ponteiro pro nó
        } else {
            if (no->chave > chave) {
                no = no->esq;
            } else {
                no = no->dir;
            }
        }
    }
    return NULL; // não achou, retorna null
}

TNoA* buscaRecursiva(TNoA *no, int chave) {
    if (no == NULL) {
        return NULL;
    } else if (no->chave == chave) {
      	return no;
    } else if (no->chave > chave) {
      	return buscaRecursiva (no->esq, chave);
    } else {
      	return buscaRecursiva (no->dir, chave);
    }    
}

TNoA* insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *)malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave)) {
        no->esq = insere(no->esq, chave);
    } else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida!"); // chave já existe
        exit(1);
    }
    return no;
}

TNoA* criaArvoreBalanceada (TNoA *raiz, int v[], int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        raiz = insere (raiz, v[meio]);
        //constroi subárvores esquerda e direita
        criaArvoreBalanceada(raiz, v, inicio, meio - 1);
        criaArvoreBalanceada(raiz, v, meio + 1, fim);
    }
}

void imprime(TNoA *raiz, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (raiz != NULL) {
        printf("%d\n", raiz->chave);
        imprime(raiz->esq, tab + 4);
        printf("\n");
        imprime(raiz->dir, tab + 4);
    } else {
        printf("vazio");
    }
}

int main (void) {
    int tam = 7;
    int v[] = {150, 300, 400, 500, 700, 800, 900};
    TNoA *raiz;
    raiz = NULL;
    raiz = criaArvoreBalanceada(raiz, v, 0, tam - 1);
    imprime(raiz, 0);
    
    return 0;
}