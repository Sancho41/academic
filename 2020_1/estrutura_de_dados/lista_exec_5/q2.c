// A função que remove os repetidos se encontra na linha 77

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
  int valor;
  struct registro *prox;
} registro;

typedef struct lista
{
  struct registro *inicio;
  int qtd;
} lista;

registro *cria_registro(int valor);
lista *cria_lista();
void adiciona_lista(lista *l, int valor);
lista *remove_repetidos(lista *l);
void mostra_lista(lista *l);

int main()
{
  char *input;
  char *digito_input;
  int digito;
  lista *l1, *l2;

  // Cria uma nova lista
  l1 = cria_lista();

  // Recebe a lista de números numa string
  printf("Digite a lista de números separdos por espaço: \n");
  scanf("%m[^\n]s", &input);

  digito_input = strtok(input, " \n");

  // Percorre a string e adiciona os números na lista
  while (digito_input != NULL)
  {

    // Converte o número string para inteiro
    digito = atoi(digito_input);

    // Adiciona na lista
    adiciona_lista(l1, digito);
    digito_input = strtok(NULL, " \n");
  }

  // Mostra a lista original
  printf("Lista original: ");
  mostra_lista(l1);

  // Cria uma nova lista sem os números repetidos
  l2 = remove_repetidos(l1);

  // Mostra a segunda lista
  printf("Lista Sem repetições: ");
  mostra_lista(l2);
}

void mostra_lista(lista *l)
{
  registro *aux;
  aux = l->inicio;
  while (aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}

lista *remove_repetidos(lista *l)
{
  int valor;
  registro *aux_nova, *aux, *novo;
  lista *nova_lista;

  nova_lista = cria_lista();

  // Percorre a lista original
  aux = l->inicio;
  while (aux != NULL)
  {
    valor = aux->valor;

    // Percorre a segunda lista para adicionar no final
    // se encontrar um número igual, não adciona
    aux_nova = nova_lista->inicio;

    if (aux_nova == NULL)
    {
      nova_lista->inicio = cria_registro(valor);
      nova_lista->qtd++;
    }
    else
    {
      // Procura pelo último elemento ou por algum valor correspondente;
      while (aux_nova->prox != NULL)
      {
        if (aux_nova->valor == valor)
          break;
        aux_nova = aux_nova->prox;
      }

      // Verifica se o elemento encontrado é o último ou é igual ao valor
      if (aux_nova->valor != valor)
      {
        novo = cria_registro(valor);
        aux_nova->prox = novo;
        nova_lista->qtd++;
      }
    }

    aux = aux->prox;
  }

  return nova_lista;
}

// Cria um novo registro
registro *cria_registro(int valor)
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
void adiciona_lista(lista *l, int valor)
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
