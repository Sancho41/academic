// Para compilar com as bibliotecas 
// gcc -fopenmp bubblesort_times.c -lm

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

void mergesort(long int * vetor, long int inicio, long int fim);
void intercala(long int * vetor, long int inicio, long int meio, long int fim);

int main () {
  double t_final, t_inicial;
  long int i, j, tam, *vetor;

  for (i = 1; i <= 6; i++) {

    tam = (long int)pow((double)10, (double)i);

    printf("Vetor de tamanho %ld:\n", tam);

    vetor = malloc(sizeof(long int) * tam);

    t_inicial = omp_get_wtime();
    for (j = 0; j < tam; j++) {
      vetor[j] = rand() % tam;
    }
    t_final = omp_get_wtime();
    printf("Criar:   %lfs\n", t_final - t_inicial);

    t_inicial = omp_get_wtime();
    mergesort(vetor, 0, tam - 1);
    t_final = omp_get_wtime();
    printf("Ordenar: %lfs\n\n", t_final - t_inicial);

    free(vetor);

  }

  

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
