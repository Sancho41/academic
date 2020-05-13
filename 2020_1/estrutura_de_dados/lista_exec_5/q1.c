
// a função que reordena a lista começa a partir da linha 74.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
  char valor;
  struct registro *prox;
} registro;

typedef struct lista
{
  struct registro *inicio;
  int qtd;
} lista;

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

registro *cria_registro(char valor);
lista *cria_lista();
void adiciona_lista(lista *l, char valor);
pilha *cria_pilha();
void push_pilha(pilha *p, char valor);
char pop_pilha(pilha *p);
fila *cria_fila();
void push_fila(fila *f, char valor);
char pop_fila(fila *f);
lista *reordena(lista *l);
int eh_digito(char valor);
void mostra_lista(lista *l);

int main()
{
  char *string;
  int i;
  lista *l1, *l2;
  registro *aux;
  l1 = cria_lista();

  printf("Entre com a lista de caracteres: ");
  scanf("%ms", &string);

  // Percorre a string e coloca na lista encadeada
  for (i = 0; i < strlen(string); i++)
  {
    adiciona_lista(l1, string[i]);
  }

  // Mostra na tela a string que foi digitada
  mostra_lista(l1);

  // Recebe lista reordenada
  l2 = reordena(l1);

  // Percorre a lista reordenada e mostra na tela
  mostra_lista(l2);
}

// Reordena a lista
lista *reordena(lista *l)
{

  registro *aux;
  pilha *p;
  fila *f;
  lista *lista_reordenada;
  char valor;

  p = cria_pilha();
  f = cria_fila();
  lista_reordenada = cria_lista();

  aux = l->inicio;

  // Percorre a lista
  while (aux != NULL)
  {
    valor = aux->valor;

    // Se o elemento for um dígito ele é adicionado na pilha
    // se não é adicionado na fila
    if (eh_digito(valor))
    {
      push_pilha(p, valor);
    }
    else
    {
      push_fila(f, valor);
    }

    aux = aux->prox;
  }

  // Vai retirando os elemntos das fila e adicionando na lista nova
  while (f->qtd != 0)
  {
    adiciona_lista(lista_reordenada, pop_fila(f));
  }

  // Vai retirando os elemntos das pilhas e adicionando na lista nova
  while (p->qtd != 0)
  {
    adiciona_lista(lista_reordenada, pop_pilha(p));
  }

  return lista_reordenada;
}

// Cria um novo registro
registro *cria_registro(char valor)
{
  registro *new;
  new = (registro *)malloc(sizeof(registro));
  new->valor = valor;
  new->prox = NULL;
  return new;
}

// Cria uma nova estrutura de lista
lista *cria_lista()
{
  lista *new;
  new = (lista *)malloc(sizeof(lista));
  new->inicio = NULL;
  new->qtd = 0;
  return new;
}

// Adiciona um novo registro no final da lista
void adiciona_lista(lista *l, char valor)
{
  registro *aux, *new;
  new = cria_registro(valor);

  aux = l->inicio;

  // Se a lista estiver vazia adiciona no início
  if (aux == NULL)
  {
    l->inicio = new;
  }
  else
  {
    // Percorre toda a lista para achar o último elemnto
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = new;
  }

  l->qtd++;
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
void push_pilha(pilha *p, char valor)
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
char pop_pilha(pilha *p)
{
  char valor;
  registro *aux;
  aux = p->topo;

  if (aux != NULL)
  {
    valor = aux->valor;
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
void push_fila(fila *f, char valor)
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
char pop_fila(fila *f)
{
  char valor;
  registro *aux;
  aux = f->topo;
  if (aux != NULL)
  {
    valor = aux->valor;
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

// Verifica se o char é um digito
int eh_digito(char valor)
{
  char digitos[10] = "1234567890";
  int i;

  for (i = 0; i < 10; i++)
  {
    if (valor == digitos[i])
      return 1;
  }

  return 0;
}

void mostra_lista(lista *l)
{
  registro *aux;
  aux = l->inicio;
  while (aux != NULL)
  {
    printf("%c ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}