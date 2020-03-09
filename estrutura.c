#include <stdio.h>
#include <malloc.h>

typedef struct {
    int c1;
    int c2;
} teste, *pont;

pont copiar(teste t1) {
    pont x = (pont) malloc(sizeof(teste));
    *x = t1;
    return x;
}

int main () {
    teste y;
    y.c1 = 10;
    y.c2 = 22;
    pont w = copiar(y);
    printf("c1: %i, c2 %i\n", w->c1, w->c2);
}
