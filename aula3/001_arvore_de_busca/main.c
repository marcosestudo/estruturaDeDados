#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    char info;
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA *busca(TNoA *no, int chave) {
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