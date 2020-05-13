// Implemente uma lista duplamente ligada e adicione uma opção 
// que remova todos os números primos dessa lista.

#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
  int valor;
  struct registro * ant;
  struct registro * prox;
}registro;

typedef struct lista {
  struct registro * inicio;
  struct registro * fim;
  int qtd;
}lista;

lista * aloca_lista();
registro * aloca_registro();
void adiciona(lista * l, int valor);
void mostrar(lista * l);
void remove_primos(lista * l);
int primo(int valor);
void menu(lista * l);

int main () {

  lista * l = aloca_lista();
  menu(l);
  
  return 0;
}

lista * aloca_lista(){
  lista * l = (lista*)malloc(sizeof(lista));
  l->inicio = NULL;
  l->fim = NULL;
  l->qtd = 0;
  return l;
}

registro * aloca_registro(){
  registro * r = (registro*)malloc(sizeof(registro));
  r->ant = NULL;
  r->prox = NULL;
  r->valor = 0;
}

void adiciona(lista * l, int valor){
  registro * r = aloca_registro();
  r->valor = valor;

  if (l->qtd == 0) {
    l->inicio = r;
    l->fim = r;
  } else {
    l->fim->prox = r;
    r->ant = l->fim;
    l->fim = r;
  }

  l->qtd++;
}

void mostrar(lista * l){
  registro * aux;

  aux = l->inicio;
  while(aux) {
    printf("valor: %d\n", aux->valor);
    aux = aux->prox;
  }

}

void remove_primos(lista * l){
  registro * aux, * frente, * tras;

  aux = l->inicio;
  while(aux) {
    if(primo(aux->valor)){
      
      frente = aux->prox;
      tras = aux->ant;

      if (!tras)
        l->inicio = frente;
      else tras->prox = frente;
      
      if (!frente)
        l->fim = tras;
      else frente->ant = tras;
    }

    aux = aux->prox;
  }
}

int primo(int valor){
  int i;

  if (valor <= 1)
    return 0;

  for (i = 2; i < valor; i++) {
    if (valor % i == 0 && valor != i)
      return 0;
  }

  return 1;
}

void menu (lista * l) {
  int op, valor;

  do {
    printf("-----------------\n");
    printf("1 -      Adiciona\n");
    printf("2 -        Mostra\n");
    printf("3 - Remove Primos\n");
    printf("0 -          Sair\n");
    scanf("%d", &op);

    switch(op) {
      case 0:
        printf("Saindo...\n");
      break;
      case 1:
        scanf("%d", &valor);
        adiciona(l, valor);
        printf("Adicionado valor: %d\n", valor);
      break;

      case 2:
        printf("Mostrando lista\n");
        mostrar(l);
      break;

      case 3:
        remove_primos(l);
        printf("Numeros primos removidos\n");
      break;
      
      default:
        printf("Opcao invalida\n");
      break;
    }


  } while (op != 0);
}
