#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct {
    int peso; //peso em kg
    int altura; //altura em cm
} PesoAltura;

int main() {
    int x;
    PesoAltura* pessoa1;
    printf("Valor inicial do endereco: %i\n", pessoa1);
    pessoa1= (PesoAltura*) malloc(sizeof(PesoAltura));
    printf("Peso: %i, Altura: %i. ", pessoa1->peso, pessoa1->altura);
    pessoa1->peso = 90;
    pessoa1->altura = 185;
    
    printf("Peso: %i, Altura: %i. ", pessoa1->peso, pessoa1->altura);
    if (pessoa1->altura>alturaMaxima) {
        printf("Altura acima da maxima.\n");
    }        
    else printf ("Altura abaixo da maxima.\n");
    
    printf("Enderecos: %i %i %i\n", &x, &pessoa1, pessoa1);

    return 0;
}