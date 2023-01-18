#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    char info;
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;
