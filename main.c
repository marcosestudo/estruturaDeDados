#include <stdio.h>
#include <stdlib.h>

struct lista {
  	int info;
	struct lista *prox;
};
typedef struct lista TLista;

TLista* cria_lista(void) {
	return NULL;
}

TLista* insere_inicio(TLista *li, int n) {
	TLista *novo = (TLista*)malloc(sizeof(Tlista));
	novo->info = n;
	novo->prox = li;
	return novo;
}

void imprime_lista(TLista *li) {
	TLista *p;
	for (p = li; p != NULL; p = p->prox) {
		printf("|%d|| ", p->info);
	}
}

int main(void) {
	Tlista *L;

	L = cria_lista;
    
  	return 0;
}