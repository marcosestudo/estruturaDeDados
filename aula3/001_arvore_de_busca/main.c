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
        printf("Inserção inválida"); // chave já existe
        exit(1);
    }
    return no;
}