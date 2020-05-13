#include <stdio.h>
#include <stdlib.h>
#define tam 10

void bubblesort(int * vet, int qtd);

int main () {
  int vetor [tam] = {1, 3, 4, 8, 5, 2, 10, 6, 7, 9}, i;

  printf("mostrando vetor:\n");

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  bubblesort(vetor, tam);

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  return 0;
}


void bubblesort(int * vet, int qtd) {
  int aux, pass, trocou, i;

  trocou = 1;

  for ( pass = 0; pass < qtd - 1 && trocou ; pass++) {
    trocou = 0;

    for (i = 0; i < qtd - 1 - pass; i++){
      if (vet[i] > vet[i + 1]) {
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
        trocou = 1;
      }
    }

  }

}