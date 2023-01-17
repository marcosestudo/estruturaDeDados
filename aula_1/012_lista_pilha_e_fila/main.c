#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
};
typedef struct ponto TPonto;

int main(void) {
	TPonto *p;

    p = (TPonto*)malloc(sizeof(TPonto));

	printf("x: ");
	scanf("%f", &p->x);

	printf("y: ");
	scanf("%f", &p->y);

	printf("[%.2f, %.2f]", p->x, p->y);

	return 0;
}