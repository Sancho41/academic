#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
  int tempo;
  struct registro *prox;
} registro;

typedef struct fila
{
  int qtd;
  struct registro *inicio, *fim;
} fila;

fila *aloca_fila();
void push(fila *f, int tempo);
int pop(fila *f);

int main()
{
  int qtd, input, i, sum = 0;
  fila *f;
  int *a;
  sum = 0;
  f = aloca_fila();

  scanf("%d", &qtd);

  a = (int *)malloc(sizeof(int) * qtd);

  for (i = 0; i < qtd; i++)
  {
    scanf("%d", &a[i]);
  }

  while (a[qtd - 1] != 0)
  {
    for (i = 0; i < qtd; i++)
    {
      if (a[i] > 2)
      {
        push(f, 2);
        a[i] -= 2;
      }
      else
      {
        push(f, a[i]);
        a[i] = 0;
      }
    }

    while (f->qtd != 0)
    {
      sum += pop(f);
    }
  }

  printf("%d\n", sum);

  return 0;
}

fila *aloca_fila()
{
  fila *f = (fila *)malloc(sizeof(fila));
  f->qtd = 0;
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

void push(fila *f, int tempo)
{
  registro *r = (registro *)malloc(sizeof(registro));
  r->prox = NULL;
  r->tempo = tempo;

  if (f->qtd == 0)
    f->inicio = r;
  else
    f->fim->prox = r;

  f->fim = r;
  f->qtd++;
}

int pop(fila *f)
{
  registro *aux;
  int tempo = -1;

  aux = f->inicio;

  if (aux)
  {
    tempo = aux->tempo;
    f->inicio = f->inicio->prox;
    f->qtd--;
    free(aux);
  }
  return tempo;
}
