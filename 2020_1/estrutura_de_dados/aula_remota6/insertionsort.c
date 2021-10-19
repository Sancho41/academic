#include <stdio.h>
#include <stdlib.h>
#define tam 10

void insertion(int *vetor, int tamanho);

int main () {
  int vetor [tam] = {1, 3, 4, 8, 5, 2, 10, 6, 7, 9}, i;

  printf("mostrando vetor:\n");

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  insertion(vetor, tam);

  for ( i = 0; i < tam; i++) 
    printf("%d ", vetor[i]);
  printf("\n");

  return 0;
}


void insertion(int *vetor, int tamanho)
{
  int i, j, aux;

  for (i = 1; i < tamanho; i++)
  {
    aux = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > aux)
    {
      vetor[j + 1] = vetor[j];
      j--;
    }
    vetor[j + 1] = aux;
  }
}
