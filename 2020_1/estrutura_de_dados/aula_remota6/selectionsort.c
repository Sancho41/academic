#include <stdio.h>
#include <stdlib.h>
#define tam 10

void selection(int *vetor, int tamanho);

int main () {
  int vetor [tam] = {1, 3, 4, 8, 5, 2, 10, 6, 7, 9}, i;

  printf("mostrando vetor:\n");

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  selection(vetor, tam);

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  return 0;
}

void selection(int *vetor, int tamanho)
{
  int i, j, min, aux;
  for (i = 0; i < tamanho - 1; i++)
  {
    min = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (vetor[j] < vetor[min])
        min = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[min];
    vetor[min] = aux;
  }
}