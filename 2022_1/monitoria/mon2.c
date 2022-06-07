#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct cartas
{

  int *fila;
  int qtd;
  int inicio;
  int fim;

} cartas;

void push(cartas *a, int numero);
int pop(cartas *a);

int main()
{

  int numero = 5;
  cartas a;
  int i;

  // scanf("%d", &numero);

  a.inicio = 0;
  a.fim = 0;
  a.qtd = 0;
  a.fila = (int *)calloc(sizeof(int), TAM);

  push(&a, 1);
  push(&a, 2);
  push(&a, 3);
  pop(&a);
  pop(&a);
  pop(&a);
  push(&a, 1);
  push(&a, 2);
  push(&a, 3);

  for (i = 0; i < a.qtd; i++)
    printf("%d, ", a.fila[(i + a.inicio) % TAM]);

  printf("\n");

  for (i = 0; i < TAM; i++)
    printf("%d, ", a.fila[i]);

  printf("\n");

  return 0;
}

void push(cartas *a, int numero)
{
  if (a->qtd != TAM)
  {
    a->fila[a->fim] = numero;
    a->qtd++;
    a->fim = (a->inicio + a->qtd) % TAM;
  }
}

int pop(cartas *a)
{
  int carta_removida;
  if (a->qtd != 0)
  {
    carta_removida = a->fila[a->inicio];
    a->fila[a->inicio] = 0;
    a->inicio = (a->inicio + 1) % TAM;
    a->qtd--;
  }

  return carta_removida;
}
