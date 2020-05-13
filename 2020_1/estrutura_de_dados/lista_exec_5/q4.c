// Ajustado função que retornava verdadeiro caso a pilha não estivesse vazia
// A função que verifica a sequência começa na linha 44

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
  char valor;
  struct registro *prox;
} registro;

typedef struct pilha
{
  struct registro *topo;
  int qtd;
} pilha;

int verifica_sequencia(char *sequencia);
registro *cria_registro(char valor);
pilha *cria_pilha();
void push(pilha *p, char valor);
char pop(pilha *p);

int main()
{
  char *input;

  // Recebe a sequencia de inputs do usuário
  printf("Digite a se quência de Inserções (I) e eliminações (E) sem espaços: ");
  scanf("%ms", &input);

  // Verifica se a sequencia é válida
  if (verifica_sequencia(input) == 1)
  {
    printf("Sequência válida.\n");
  }
  else
  {
    printf("Sequência inválida.\n");
  }

  return 0;
}

int verifica_sequencia(char *sequencia)
{
  int i;
  pilha *p;

  p = cria_pilha();

  // Percorre a sequencia
  for (i = 0; i < strlen(sequencia); i++)
  {
    // Se a o char for igual a 'I' ele só coloca na fila
    if (sequencia[i] == 'I')
    {
      push(p, 'I');
    }
    else
    {
      // Se o pop da pilha não for igua a 'I' a sequencia é inválida
      if (pop(p) != 'I')
      {
        return 0;
      }
    }
  }

  // Retorna 1 se a pilha estiver vazia
  // 0 se ainda estiver alguma coisa
  if (p->topo == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
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
void push(pilha *p, char valor)
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
char pop(pilha *p)
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
