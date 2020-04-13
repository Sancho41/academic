#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
  int valor;
  struct registro * prox;
}registro;

typedef struct lista {
  int qtd;
  struct registro * inicio;
}lista;

registro * aloca_registro();
lista * aloca_lista();
void adiciona(lista * l, int valor);
void busca(lista * l, int valor);
void mostrar(lista *l);
void menu(lista * l);

int main () {
  lista * l;
  l = aloca_lista();
  menu(l);
  return 0;
}

registro * aloca_registro() {
  registro * r = (registro*)malloc(sizeof(registro));
  r->valor = 0;
  r->prox = NULL;
  return r;
}

lista * aloca_lista() {
  lista * l = (lista*)malloc(sizeof(lista));
  l->inicio = NULL;
  l->qtd = 0;
  return l;
}

void adiciona(lista * l, int valor) {
  registro * aux, * r = aloca_registro();
  r->valor = valor;

  aux = l->inicio;
  if (!aux) {
    l->inicio = r;
    return;
  }

  while(aux->prox) {
    aux = aux->prox;
  }
  aux->prox = r;
}

void busca(lista * l, int valor) {
  registro * ant, * aux, * prox;

  aux = l->inicio;
  ant = NULL;
  prox = aux->prox;

  while (aux) {
    if (aux->valor == valor){
      if (ant)
        printf("%d", ant->valor);
      else
        printf("-");
      
      printf(" %d ", aux->valor);

      if (prox)
        printf("%d\n", prox->valor);
      else
        printf("-\n");

      return;
    }

    ant = aux;
    aux = aux->prox;
    if (aux)
      prox = aux->prox;
  }
  printf("Numero não encontrado\n");
}

void mostrar(lista *l) {
  registro * aux;
  aux = l->inicio;
  while(aux) {
    printf("valor: %d\n", aux->valor);
    aux = aux->prox;
  }
}

void menu(lista * l) {
  int op, valor;

  do {

    printf("1 - Adiciona\n");
    printf("2 - Mostra\n");
    printf("3 - Busca e mostra anterior e proximo\n");
    printf("0 - Sair\n");
    scanf("%d", &op);

    switch(op) {
      case 1:
        scanf("%d", &valor);
        adiciona(l, valor);
        printf("Adicionado valor: %d\n", valor);
        break;
      case 2:
        printf("Mostrando\n");
        mostrar(l);
        break;
      case 3:
        scanf("%d", &valor);
        printf("Buscando pelo valor %d\n", valor);
        busca(l, valor);
        break;
      case 0:
        printf("Saindo\n");
        break;
      default:
        break;
    }

  }while (op);
}