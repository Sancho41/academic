/*
    Dia 10/02 - Lista Ligadas
    Um elemento tem uma referência para próximo elemento
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int qtd;
  struct registro *inicio;
} lista;

typedef struct registro
{
  int prioridade;
  int complexidade;
  int tempo;
  struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro(int p, int c, int t);
void incluir(lista *l, int p, int c, int t);
void adiciona_antes(lista *l, registro *aux, registro *ant, registro *novo);
void adiciona_depois(registro *aux, registro *novo);

int main()
{
  int prioridade;
  int complexidade;
  int tempo;
  int max;
  int qtd;
  int i, count = 0;
  int sum = 0;
  registro *aux;
  lista *l1;
  l1 = aloca_lista();

  scanf("%d %d", &qtd, &max);
  max = max * 24;

  for (i = 0; i < qtd; i++)
  {
    scanf("%d %d %d", &prioridade, &complexidade, &tempo);
    incluir(l1, prioridade, complexidade, tempo);
    aux = l1->inicio;
    while (aux != NULL)
    {
      printf("%d : %d : %d\n", aux->prioridade, aux->complexidade, aux->tempo);
      sum += aux->tempo;
      count++;
      aux = aux->prox;
    }
    printf("=====\n");
  }

  aux = l1->inicio;
  // while (aux != NULL && sum < max)
  // {
  //   sum += aux->tempo;
  //   count++;
  //   aux = aux->prox;
  // }

  while (aux != NULL)
  {
    printf("%d : %d : %d\n", aux->prioridade, aux->complexidade, aux->tempo);
    sum += aux->tempo;
    count++;
    aux = aux->prox;
  }

  if (sum > max)
  {
    printf("%d\n", count - 1);
  }
  else
  {
    printf("%d\n", count);
  }

  return 0;
}

lista *aloca_lista()
{
  struct lista *novo;
  novo = (lista *)malloc(sizeof(lista));
  novo->inicio = NULL;
  novo->qtd = 0;
  return novo;
}

registro *aloca_registro(int p, int c, int t)
{
  struct registro *novo;
  novo = (registro *)malloc(sizeof(registro));
  novo->prioridade = p;
  novo->complexidade = c;
  novo->tempo = t;
  novo->prox = NULL;
  return novo;
}

void adiciona_antes(lista *l, registro *aux, registro *ant, registro *novo)
{
  if (ant == NULL)
  {
    novo->prox = l->inicio;
    l->inicio = novo;
  }
  else
  {
    novo->prox = aux;
    ant->prox = novo;
  }
}

void adiciona_depois(registro *aux, registro *novo)
{
  novo->prox = aux->prox;
  aux->prox = novo;
}

void incluir(lista *l, int p, int c, int t)
{
  // Cria novo registro
  registro *novo;
  registro *aux, *ant = NULL, *aux2, *ant2;
  novo = aloca_registro(p, c, t);
  int adicionou = 0;

  // Adiciona novo registro na lista
  if (l->qtd == 0)
    l->inicio = novo;
  else
  {
    aux = l->inicio;
    while (aux != NULL && adicionou == 0)
    {
      if (novo->prioridade < aux->prioridade)
      {
        adiciona_antes(l, aux, ant, novo);
        adicionou = 1;
      }
      else if (novo->prioridade == aux->prioridade)
      {
        while (aux != NULL && adicionou != 1)
        {
          if (novo->prioridade != aux->prioridade)
            break;

          if (novo->complexidade > aux->complexidade)
          {
            adiciona_antes(l, aux, ant, novo);
            adicionou = 1;
          }
          else if (novo->complexidade == aux->complexidade)
          {
            while (aux != NULL && adicionou != 1)
            {
              if (novo->complexidade != aux->complexidade && novo->prioridade != aux->prioridade)
                break;

              if (novo->tempo < aux->tempo)
              {
                adiciona_antes(l, aux, ant, novo);
                adicionou = 1;
              }
              ant = aux;
              aux = aux->prox;
            }

            if (adicionou == 0)
            {
              if (ant != NULL)
              {
                ant->prox = novo;
                novo->prox = aux;
              }
              else
              {
                novo->prox = l->inicio;
                l->inicio = novo;
              }

              adicionou = 1;
            }
          }
          else
          {
            ant = aux;
            aux = aux->prox;
          }
        }

        if (adicionou == 0)
        {
          if (ant != NULL)
          {
            ant->prox = novo;
            novo->prox = aux;
          }
          else
          {
            novo->prox = l->inicio;
            l->inicio = novo;
          }

          adicionou = 1;
        }
      }
      else
      {
        ant = aux;
        aux = aux->prox;
      }
    }

    if (adicionou == 0)
    {
      if (ant == NULL)
      {
        novo->prox = l->inicio;
        l->inicio = novo;
      }
      else
      {
        ant->prox = novo;
        novo->prox = aux;
      }
    }
  }
  l->qtd++;
}
