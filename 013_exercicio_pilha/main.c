#include <stdio.h>
#include <stdlib.h>

struct lista {
  	int info;
	struct lista *prox;
};
typedef struct lista TLista;

// #include "lista-encadeada.h"
struct pilha {
    TLista *topo;
};
typedef struct pilha TPilha;

int pilha_vazia(TPilha *pilha) {
    if (pilha->topo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

TPilha *inicializa() {
    TPilha *pilha = (TPilha*)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void push(TPilha *pilha, int elem) {
    TLista *novo = (TLista*)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(TPilha *pilha) {
    if (pilha_vazia(pilha)) {
        exit(1);
    } else {
        TLista *aux = pilha->topo;
        int info = aux->info;
        pilha->topo = aux->prox;
        free(aux);
        return info;
    }
}

int peek(TPilha *pilha) {
    if (pilha_vazia(pilha)) {
        return -1;
    } else {
        return pilha->topo->info;
    }
}

void imprime(TLista *li) {
	TLista *p;
	for (p = li; p != NULL; p = p->prox) {
		printf("|%d|| ", p->info);
	}
}

int main(void) {
    TPilha *pilha = inicializa();
    
    push(pilha, 5);
    printf("Topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("Topo: %d\n", peek(pilha));
    push(pilha, 3);
    int info = pop(pilha);
    printf("Removido: %d\n", info);
    
  	return 0;
}