// typedef struct sNoAVL {
//     int chave;
//     int fb; // fazer recursivamente atualizacao dos fb ate encontrar um no com fb 0 ou +/- 2 depois de atualizado, se desbalancear, fazer rotacao
//     struct sNoAVL *esq; // fb -1 quando adicionado, fb -1 quando removido
//     struct sNoAVL *dir; // fb +1 qunado adicionado, fb -1 quando removido
// } TNoA;

// TNoA* rotacao_direita(TNoA *p) {
//     TNoA *u;
//     u = p->esq;
//     p->esq = u->dir;
//     u->dir = p;
//     p = u;
//     return p;
// }

// TNoA* rotacao_esquerda(TNoA *p) {
//     TNoA *z;
//     z = p->dir;
//     p->dir = z->esq;
//     z->dir = p;
//     p = z;
//     return p;
// }

// TNoA* rotacao_dupla_direita(TNoA *p) {
//     rotacao_esquerda(p->esq);
//     rotacao_direita(p);
//     return p;
// }

// TNoA* rotacao_dupla_esquerda(TNoA *p) {
//     rotacao_direita(p->dir);
//     rotacao_esquerda(p);
//     return p;
// }
