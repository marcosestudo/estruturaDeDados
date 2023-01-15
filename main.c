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
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->info = n;
	novo->prox = li;
	return novo;
}

TLista* insere_fim (TLista *li, int n) {
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->info = n;
	novo->prox = NULL;
	TLista *p = li;
	TLista *ant = li;
	while (p != NULL) {
		ant = p;
		p = p->prox;
	}
	if (ant != NULL) {
		ant->prox = novo;
	} else {
		li = novo;
	}
	return li;
}

TLista* insere_ordenado (TLista *li, int n) {
	TLista *novo;
	TLista *ant = NULL;
	TLista *p = li;
	// procura posicao para insercao
	while (p != NULL && p->info < n) {
		ant = p;
		p = p->prox;
	}
	// cria novo elemento
	novo = (TLista*)malloc(sizeof(TLista));
	novo->info = n;
	// encadeia elemento
	if (ant == NULL) {
		novo->prox = li;
		li = novo;
	} else {
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return li;
}

TLista* insere_fim_recursivo(TLista *li, int n) {
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->info = n;
	novo->prox = NULL;
	if (li == NULL) {
		li = novo;
	} else {
		if (li->prox == NULL) {
			li->prox = novo;
		} else {
			insere_fim_recursivo(li->prox, n);
		}
	}
	return li;
}

TLista* insere_ordenado_recursivo(TLista *li, TLista *ant, int n) {
	TLista *novo = (TLista*)malloc(sizeof(TLista));
	novo->info;
	if (li == NULL) {
		li = novo;
		novo->prox = NULL;
	} else {
		if (li->info > n) {
			novo->prox = li;
			li = novo;
			if (ant != NULL) {
				ant->prox = novo;
			}
		} else {
			if (li->prox == NULL) {
				li->prox = novo;
				novo->prox = NULL;
			} else {
				insere_ordenado_recursivo(li->prox, li, n);
			}
		}
	}
	return li;
}

void imprime_lista(TLista *li) {
	TLista *p;
	for (p = li; p != NULL; p = p->prox) {
		printf("|%d|| ", p->info);
	}
}

int main(void) {
	TLista *L;

	L = cria_lista;
    
  	return 0;
}