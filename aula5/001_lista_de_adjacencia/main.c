#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho {
    int id_vizinho;
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    int id_vertice;
    TVizinho *prim_vizinho;
    struct grafo *prox;
} TGrafo;

TGrafo* inicializa() {
    return NULL;
}

void imprime(TGrafo *g) {
    TVizinho *v;
    while (g != NULL) {
        printf("Vértice %d \n", g->id_vertice);
        printf("Vizinhos: ");
        v = g->prim_vizinho;
        while(v != NULL) {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");
        g = g->prox;
    }
}

void libera_vizinhos(TVizinho *v) {
    while(v != NULL) {
        TVizinho *temp = v;
        v = v->prox;
        free(temp);
    }
}

void libera(TGrafo *g) {
    while (g != NULL) {
        libera_vizinhos(g->prim_vizinho);
        TGrafo *temp = g;
        g = g->prox;
        free(temp);
    }
}

TGrafo* busca_vertice(TGrafo *g, int x) {
    while ((g != NULL) && (g->id_vertice != x)) {
        g = g->prox;
    }
    return g;
}

TVizinho* busca_aresta(TGrafo *g, int v1, int v2) {
    TGrafo *pv1 = busca_vertice(g, v1);
    TGrafo *pv2 = busca_vertice(g, v2);
    TVizinho *resp = NULL;
    // checa se ambos os vértices existem
    if ((pv1 != NULL) && (pv2 != NULL)) {
        // percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_vizinho;
        while ((resp != NULL) && (resp->id_vizinho != v2)) {
            resp = resp->prox;
        }
    }
    return resp;
}

TGrafo *insere_vertice(TGrafo *g, int x) {
    TGrafo *p = busca_vertice(g, x);
    if (p == NULL) {
        p = (TGrafo*)malloc(sizeof(TGrafo));
        p->id_vertice = x;
        p->prox = g;
        p->prim_vizinho = NULL;
        g = p;
    }
    return g;
}

void insere_um_sentido(TGrafo *g, int v1, int v2) {
    TGrafo *p = busca_vertice(g, v1);
    // deveria buscar também o segundo vértice?
    TVizinho *nova = (TVizinho *)malloc(sizeof(TVizinho));
    nova->id_vizinho = v2;
    nova->prox = p->prim_vizinho;
    p->prim_vizinho = nova;
}

// insere nos dois sentidos pra grafo não orientado
void insere_aresta(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if (v == NULL) {
        insere_um_sentido(g, v1, v2);
        insere_um_sentido(g, v2, v1);
    }
}

void insere_aresta_digrafo(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if (v == NULL) {
        insere_um_sentido(g, v1, v2);
    }
}

void retira_um_sentido(TGrafo *g, int v1, int v2) {
    TGrafo *p = busca_vertice(g, v1);
    if (p != NULL) {
        TVizinho *ant = NULL;
        TVizinho *atual =  p->prim_vizinho;
        while ((atual != NULL) && (atual->id_vizinho != v2)) {
            ant = atual;
            atual = atual->prox;
        }
        if (ant == NULL) //v2 era o primeiro nó da lista 
            p->prim_vizinho = atual->prox;
        else 
            ant->prox = atual->prox;
        free(atual);
    }
}

// retira nos dois sentidos pra grafo não orientado
void retira_aresta(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if (v != NULL) {
        retira_um_sentido(g, v1, v2);
        retira_um_sentido(g, v2, v1);
    }
}

void retira_aresta_digrafo(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if (v != NULL) {
        retira_um_sentido(g, v1, v2);
    }
}

TGrafo *retira_vertice(TGrafo *g, int v) {
    TGrafo *ant, *vertice = g;
    TVizinho *vAnt;

    while (g && g->id_vertice != v) {
        ant = g;
        g = g->prox;
    }
    while(g->prim_vizinho) {
        vAnt = g->prim_vizinho;
        retira_um_sentido(vertice, g->prim_vizinho->id_vizinho, v);
        g->prim_vizinho = g->prim_vizinho->prox;
        free(vAnt);
    }
    ant->prox = g->prox;
    free(g);
}

int main(void) {
    TGrafo *g = inicializa();
    g = insere_vertice(g, 1);
    g = insere_vertice(g, 2);
    g = insere_vertice(g, 3);
    g = insere_vertice(g, 4);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 3);
	insere_aresta(g, 2, 4);
    imprime(g);
    retira_aresta(g, 3, 2);
    printf("Grafo após exclusão da aresta (3,2): \n\n");
    imprime(g);
    retira_vertice(g,2);
    printf("Grafo após exclusão do vértice 2: \n\n");
    imprime(g);
    libera(g);
    
    return 0;
}
