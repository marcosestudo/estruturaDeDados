#include <stdio.h>

int main(void) {
    int v[10], i;
    for (i = 0; i < 3; i++) {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < 3; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}