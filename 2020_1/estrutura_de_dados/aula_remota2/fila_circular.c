#include <stdio.h>
#include <stdlib.h>
#define tam = 10;

typedef struct fila {
    int elementos[tam];
    int atual;
    int tamanho = 0;
}fila;

int main () {
    
    int * fila;
    
    return 0;
}

int * inicializa_fila(int tamanho){
    int fila[tamanho];
    int i;
    for (i = 0; i < tamanho; i++) 
        fila[i] = NULL;

    return fila;
}

