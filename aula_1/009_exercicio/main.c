#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, *p;
    
    a = 5;
    p = &a;
    *p = 6;

    printf("Endereço de p: %d\n", &p);
    printf("Endereço de a: %p\n", &a);
    printf("Endereço que está em p: %p\n", p);
    printf("Conteúdo da variável apontadada por p: %d\n", *p);
    printf("Conteúdo de a: %d\n", a);
    
    return 0;
}