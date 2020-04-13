#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
  int valor;
  struct registro * prox;
}registro;

typedef struct fila {
  int qtd;
  struct registro * inicio, * fim;
}fila;

fila * aloca_fila();
registro * aloca_registro(int valor);
void push(fila * f, int valor);
int pop(fila * f);
int empty(fila * f);
void menu(fila * f);

int main () {
  fila * f = aloca_fila();
  menu(f);
  return 0;
}

fila * aloca_fila(){
  fila * f = (fila*)malloc(sizeof(fila));
  f->inicio = NULL;
  f->fim = NULL;
  f->qtd = 0;
  return f;
}

registro * aloca_registro(int valor){
  registro * r = (registro*)malloc(sizeof(registro));
  r->valor = valor;
  r->prox = NULL;
  return r;
}

void push(fila * f, int valor){
  registro * r = aloca_registro(valor);

  
  if (f->qtd == 0) {
    f->inicio = r;
    r->prox = r;
  } else {
    f->fim->prox = r;
    r->prox = f->inicio;
  }

  f->fim = r;
  f->qtd++;
}

int pop(fila * f){
  int valor;
  registro * aux, * ant, * prox;

  if (f->qtd == 0)
    return -1;

  aux = f->inicio;

  valor = aux->valor;
  
  f->inicio = aux->prox;


  free(aux);

  f->qtd--;
  return valor;
  
}

int empty(fila * f) {
  return f->qtd == 0;
}

void menu(fila * f){
  int op, retorno, valor;

  do {
    printf("1 - PUSH\n");
    printf("2 - POP\n");
    printf("0 - SAIR\n");
    scanf("%d", &op);

    switch(op) {
      case 0:
        printf("Saindo...\n");
        break;
      case 1:
        scanf("%d", &valor);
        printf("PUSH: %d\n", valor);
        push(f, valor);
        break;
      case 2:
        if (!empty(f))
          printf("POP: %d\n", pop(f));
        else
          printf("FILA VAZIA\n");
        break;
      default:
        printf("Opcao invalida");
        break;
    }

  }while(op);
  
}
