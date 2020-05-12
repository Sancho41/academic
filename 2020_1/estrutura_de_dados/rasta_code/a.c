#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
  struct registro *topo;
  int qtd;
} pilha;

typedef struct registro
{
  char value;
  struct registro *prox;
} registro;

registro *aloca_registro(char value);
pilha *aloca_pilha();
void push(pilha *p, char value);
char pop(pilha *p);
int empty(pilha *p);

int main()
{
  int i, j;
  pilha *p;
  char input, value;
  p = aloca_pilha();

  scanf("%d\n", &j);

  for (i = 0; i < j; i++)
  {
    scanf("%c\n", &input);
    if (input == '{' || input == '}')
    {
      if (empty(p))
      {
        push(p, input);
      }
      else
      {
        printf("lascou\n");
        return 0;
      }
    }
    else
    {
      if (!empty(p))
        value = pop(p);
      else
      {
        if (i != 0)
        {
          printf("lascou\n");
          return 0;
        }
      }
    }
  }

  if (empty(p) == 0)
  {
    printf("lascou\n");
  }
  else
  {
    printf("rasta\n");
  }

  return 0;
}

registro *aloca_registro(char value)
{
  registro *new;
  new = (registro *)malloc(sizeof(registro));
  new->value = value;
  new->prox = NULL;
  return new;
}

pilha *aloca_pilha()
{
  pilha *new;
  new = (pilha *)malloc(sizeof(pilha));
  new->qtd = 0;
  new->topo = NULL;
  return new;
}

void push(pilha *p, char value)
{
  registro *new_registro;
  new_registro = aloca_registro(value);
  new_registro->prox = p->topo;
  p->topo = new_registro;
  p->qtd++;
}

char pop(pilha *p)
{
  char value;
  registro *aux;

  if (p->qtd > 0)
  {
    aux = p->topo;
    value = aux->value;
    p->topo = aux->prox;
    p->qtd--;
    free(aux);
    return value;
  }
  return '\0';
}

int empty(pilha *p)
{
  if (p->topo == NULL)
    return 1;
  return 0;
}
