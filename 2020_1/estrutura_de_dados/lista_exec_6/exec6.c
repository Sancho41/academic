// Para compilar com as bibliotecas
// gcc -fopenmp bubblesort_times.c -lm
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void cria_vetores(int long **vetores, double *tempos, int long tamanho);
void bubblesort(int long *vet, int long qtd);
void mergesort(int long *vetor, int long inicio, int long fim);
void intercala(int long *vetor, int long inicio, int long meio, int long fim);
void insertion(int long *vetor, int long tamanho);
void selection(int long *vetor, int long tamanho);
void quick_sort(int long *vetor, int long esquerda, int long direita);

int long main()
{
  int long tamanho;
  int op = 1, i, j;
  double tempos[3];
  int long *vetores[3];
  double t_final, t_inicial;
  char *ordenacao[5] = {"BubbleSort", "InsertionSort", "SelectionSort", "MergeSort", "QuickSort"};

  // Loop que irá repetir o processo de alocar vetores e ordernar de acordo com vetor seleção do usuário
  while (op)
  {
    // Recebe o tamanho do vetor
    printf("Digite o tamanho: ");
    scanf("%ld", &tamanho);

    // Mostra as opções na tela
    printf("\nEscolha um algorítmo de ordenação:\n");
    for (i = 0; i < 5; i++)
      printf("%d. %s\n", i + 1, ordenacao[i]);
    scanf("%d", &op);

    printf("Criando vetores...\n");

    // Cria os vetores
    cria_vetores(vetores, tempos, tamanho);

    // Mostra o tempo de criação de cada vetor
    printf("Tempo de criação dos vetores:\n");
    for (i = 0; i < 3; i++)
      printf("\t%c: %f\n", i + 65, tempos[i]);

    // Ordena cada vetor com o algorítmo escolhido e armazena os tempos
    for (i = 0; i < 3; i++)
    {
      printf("Ordenando o vetor %c...\n", i + 65);

      t_inicial = omp_get_wtime();
      switch (op)
      {
      case 1:
        bubblesort(vetores[i], tamanho);
        break;
      case 2:
        insertion(vetores[i], tamanho);
        break;
      case 3:
        selection(vetores[i], tamanho);
        break;
      case 4:
        mergesort(vetores[i], 0, tamanho - 1);
        break;
      case 5:
        quick_sort(vetores[i], 0, tamanho - 1);
        break;

      default:
        break;
      }
      t_final = omp_get_wtime();

      tempos[i] = t_final - t_inicial;
    }

    // Mostra os tempos de ordenação para cada vetor
    printf("\nTempos para vetor ordenação de vetores de tamanho %ld utilizando o algorítimo %s\n", tamanho, ordenacao[op - 1]);
    for (i = 0; i < 3; i++)
      printf("\t%c: %fs\n", i + 65, tempos[i]);

    printf("Deseja fazer uma nova consulta? 1.SIM : 0.NÃO ");
    scanf("%d", &op);
  }

  return 0;
}

void cria_vetores(int long **vetores, double *tempos, int long tamanho)
{
  int long i, aux;
  double t_final, t_inicial;

  // Aloca os 3 vetores
  for (i = 0; i < 3; i++)
    vetores[i] = (int long *)malloc(sizeof(long int) * tamanho);

  // Preenche com números randômicos e pega o tempo do primeiro vetor
  t_inicial = omp_get_wtime();
  for (i = 0; i < tamanho; i++)
    vetores[0][i] = rand() % tamanho;
  t_final = omp_get_wtime();

  tempos[0] = t_final - t_inicial;

  // Preenche com números ordenados e pega o tempo do segundo vetor
  t_inicial = omp_get_wtime();
  for (i = 0; i < tamanho; i++)
    vetores[1][i] = i;
  t_final = omp_get_wtime();

  tempos[1] = t_final - t_inicial;

  // Preenche com números ordenados e pega o tempo do Terceiro vetor
  t_inicial = omp_get_wtime();
  for (i = 0; i < tamanho; i++)
    vetores[2][i] = i;

  // Troca vetor última variável pela variável do meio do terceiro vetor
  i = i / 2;
  aux = vetores[2][i];
  vetores[2][i] = vetores[2][tamanho - 1];
  vetores[2][tamanho - 1] = aux;

  t_final = omp_get_wtime();

  tempos[2] = t_final - t_inicial;
}

// Abaixo todos os algorítmos de ordenação

void quick_sort(int long *vetor, int long esquerda, int long direita)
{
  int long i, j, x, y;

  i = esquerda;
  j = direita;
  x = vetor[(esquerda + direita) / 2];

  while (i <= j)
  {
    while (vetor[i] < x && i < direita)
    {
      i++;
    }
    while (vetor[j] > x && j > esquerda)
    {
      j--;
    }
    if (i <= j)
    {
      y = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = y;
      i++;
      j--;
    }
  }

  if (j > esquerda)
  {
    quick_sort(vetor, esquerda, j);
  }
  if (i < direita)
  {
    quick_sort(vetor, i, direita);
  }
}

void selection(int long *vetor, int long tamanho)
{
  int long i, j, min, aux;
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

void insertion(int long *vetor, int long tamanho)
{
  int long i, j, aux;

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

void mergesort(int long *vetor, int long inicio, int long fim)
{
  int long meio;
  if (inicio < fim)
  {
    meio = (fim - inicio) / 2;
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio + 1, inicio);
    intercala(vetor, inicio, meio, fim);
  }
}

void intercala(int long *vetor, int long inicio, int long meio, int long fim)
{
  int long i = inicio;
  int long j = meio + 1;
  int long k = 0;
  int long *auxiliar;

  auxiliar = (int long *)malloc(sizeof(long int) * (fim - inicio + 1));

  while (i <= meio && j <= fim)
  {
    if (vetor[i] < vetor[j])
    {
      auxiliar[k++] = vetor[i++];
    }
    else
    {
      auxiliar[k++] = vetor[j++];
    }
  }

  while (i <= meio)
  {
    auxiliar[k++] = vetor[i++];
  }

  while (j <= fim)
  {
    auxiliar[k++] = vetor[j++];
  }

  i = inicio;
  for (k = 0; k < fim + inicio + 1; k++)
    vetor[i++] = auxiliar[k];

  free(auxiliar);
}

void bubblesort(int long *vet, int long qtd)
{
  int long aux, pass, trocou, i;

  trocou = 1;

  for (pass = 0; pass < qtd - 1 && trocou; pass++)
  {
    trocou = 0;

    for (i = 0; i < qtd - 1 - pass; i++)
    {
      if (vet[i] > vet[i + 1])
      {
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
        trocou = 1;
      }
    }
  }
}