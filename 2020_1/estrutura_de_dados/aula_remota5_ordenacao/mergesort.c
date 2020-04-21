#include <stdio.h>
#include <stdlib.h>

void mergesort(long int * vetor, long int inicio, long int fim);
void intercala(long int * vetor, long int inicio, long int meio, long int fim);

int main () {
  long int vetor[10] = {0, 2, 4, 6, 8, 1 ,3 ,5 ,7 ,9};
  long int i;

  mergesort(vetor, 0, 9);

  for (i = 0; i < 10; i++)
    printf("%ld ", vetor[i]);
  printf("\n");

  return 0;
}

void mergesort(long int * vetor, long int inicio, long int fim) {
  int meio;
  if ( inicio < fim ) {
    meio = (fim - inicio) / 2;
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio + 1, inicio);
    intercala(vetor, inicio, meio, fim);
  }
}

void intercala(long int * vetor, long int inicio, long int meio, long int fim) {
  long int i = inicio;
  long int j = meio + 1;
  long int k = 0;
  long int * auxiliar;

  auxiliar = (long int*)malloc(sizeof(long int)* (fim - inicio + 1));

  while ( i <= meio && j <= fim ) {
    if (vetor[i] < vetor[j]) {
      auxiliar[k++] = vetor[i++];
    } else {
      auxiliar[k++] = vetor[j++];
    }
  }

  while ( i <= meio ) {
    auxiliar[k++] = vetor[i++];
  }

  while ( j <= fim ) {
    auxiliar[k++] = vetor[j++];
  }

  i = inicio;
  for (k = 0; k < fim + inicio + 1; k++)
    vetor[i++] = auxiliar[k];

  free(auxiliar);  
}