// A função que inverte a fila começa na linha 67

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
  char *valor;
  struct registro *prox;
} registro;

typedef struct pilha
{
  struct registro *topo;
  int qtd;
} pilha;

typedef struct fila
{
  struct registro *topo;
  struct registro *base;
  int qtd;
} fila;

registro *cria_registro(char *valor);
pilha *cria_pilha();
void push_pilha(pilha *p, char *valor);
char *pop_pilha(pilha *p);
fila *cria_fila();
void push_fila(fila *f, char *valor);
char *pop_fila(fila *f);
void mostra_fila(fila *f);
void inverte_fila(fila *f);

int main()
{
  char *input;
  char *elemento;
  fila *f;
  f = cria_fila();

  // Recebe a lista de números numa string
  printf("Digite os elementos separdos por espaço: \n");
  scanf("%m[^\n]s", &input);

  elemento = strtok(input, " \n");

  // Percorre a string e adiciona os números na lista
  while (elemento != NULL)
  {

    // Adiciona na lista
    push_fila(f, elemento);
    elemento = strtok(NULL, " \n");
  }

  printf("Elementos da fila original: ");
  mostra_fila(f);

  inverte_fila(f);

  printf("fila invertida: ");
  mostra_fila(f);
}

void inverte_fila(fila *f)
{
  // Cria a pilha
  pilha *p;
  p = cria_pilha();

  // Adiciona todos os elementos da fila na pilha
  while (f->qtd > 0)
  {
    push_pilha(p, pop_fila(f));
  }

  // Coloca os elementos de volta na fila, de acordo com a
  // regra da pilha
  while (p->qtd > 0)
  {
    push_fila(f, pop_pilha(p));
  }
}

// Cria um novo registro
registro *cria_registro(char *valor)
{
  registro *new;
  new = (registro *)malloc(sizeof(registro));
  new->prox = NULL;
  new->valor = (char *)malloc(sizeof(char) * strlen(valor));
  strcpy(new->valor, valor);
  return new;
}

// Cria uma nova estrutura de pilha
pilha *cria_pilha()
{
  pilha *new;
  new = (pilha *)malloc(sizeof(pilha));
  new->topo = NULL;
  new->qtd = 0;
  return new;
}

// Adiciona um ítem na pilha
void push_pilha(pilha *p, char *valor)
{
  registro *new = cria_registro(valor);
  if (p->topo == NULL)
  {
    p->topo = new;
  }
  else
  {
    new->prox = p->topo;
    p->topo = new;
  }

  p->qtd++;
}

// Remove um elemento do topo da pilha
char *pop_pilha(pilha *p)
{
  char *valor;
  registro *aux;
  aux = p->topo;

  if (aux != NULL)
  {
    // Copia o valor para uma nova var
    valor = (char *)malloc(sizeof(char) * strlen(valor));
    strcpy(valor, aux->valor);

    p->topo = aux->prox;
    free(aux);
    p->qtd--;
    return valor;
  }
  else
  {
    return '\0';
  }
}

// Cria uma nova estrutura de pilha
fila *cria_fila()
{
  fila *new;
  new = (fila *)malloc(sizeof(fila));
  new->base = NULL;
  new->topo = NULL;
  new->qtd = 0;
  return new;
}

// Adiciona um novo elmento no final da fila
void push_fila(fila *f, char *valor)
{
  registro *new;
  new = cria_registro(valor);
  if (f->topo == NULL)
  {
    f->topo = new;
    f->base = new;
  }
  else
  {
    f->base->prox = new;
    f->base = new;
  }
  f->qtd++;
}

// Remove um elemento do início da fila
char *pop_fila(fila *f)
{
  char *valor;
  registro *aux;
  aux = f->topo;
  if (aux != NULL)
  {
    // Copia o valor para uma nova var
    valor = (char *)malloc(sizeof(char) * strlen(valor));
    strcpy(valor, aux->valor);

    f->topo = aux->prox;
    f->qtd--;
    free(aux);
    return valor;
  }
  else
  {
    return '\0';
  }
}

void mostra_fila(fila *l)
{
  registro *aux;
  aux = l->topo;
  while (aux != NULL)
  {
    printf("%s ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}