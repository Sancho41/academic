// Para compilar com as bibliotecas 
// gcc -fopenmp bubblesort_times.c -lm

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

void bubblesort(long int * vet, long int qtd);

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
    printf("Criar: %lfs\n", t_final - t_inicial);

    t_inicial = omp_get_wtime();
    bubblesort(vetor, tam);
    t_final = omp_get_wtime();
    printf("Ordenar: %lfs\n\n", t_final - t_inicial);

    free(vetor);

  }

  

  return 0;
}


void bubblesort(long int * vet, long int qtd) {
  long int aux, pass, trocou, i;

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