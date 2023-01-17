#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
};

int main(void) {
	struct ponto p;

	printf("x: ");
	scanf("%f", &p.x);

	printf("y: ");
	scanf("%f", &p.y);

	printf("[%.2f, %.2f]", p.x, p.y);

	return 0;
}