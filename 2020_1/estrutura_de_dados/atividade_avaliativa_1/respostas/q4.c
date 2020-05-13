#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct pilha {
  int qtd_esquerda;
  int qtd_direita;
  int tamTotal;
  int * vetor;
}pilha;

int push1 (pilha * p, int valor);
int push2 (pilha * p, int valor);
int pop1 (pilha * p);
int pop2 (pilha * p);
int empty1(pilha * p);
int empty2(pilha * p);
void mostrar_tudo(pilha * p);
void menu(pilha *p );

int main () {
  int i;
  pilha * p;
  p = (pilha*)malloc(sizeof(pilha));

  p->qtd_esquerda = 0;
  p->qtd_direita = 0;
  p->vetor = (int*)malloc(sizeof(int) * tam);
  p->tamTotal = tam;

  for (i = 0; i < p->tamTotal; i++) 
    p->vetor[i] = 0;

  menu(p);

  return 0;
}


int push1 (pilha * p, int valor) {
  if (p->tamTotal - p->qtd_direita != p->qtd_esquerda){
    p->vetor[p->qtd_esquerda++] = valor;
    return 1;
  }
  return 0;
}

int push2 (pilha * p, int valor) {
  if (p->tamTotal - p->qtd_esquerda != p->qtd_direita){
    p->vetor[tam - ++p->qtd_direita] = valor;
    return 1;
  }
  return 0;
}

int pop1 (pilha * p) {
  int valor;
  if (p->qtd_esquerda > 0){
    valor = p->vetor[--p->qtd_esquerda];
    p->vetor[p->qtd_esquerda] = 0; 
    return valor;
  }
}

int pop2 (pilha * p) {
  int valor;
  if (p->qtd_direita > 0){
    valor = p->vetor[tam - p->qtd_direita];
    p->vetor[tam - p->qtd_direita--] = 0;
    return valor;
  }
}

int empty1(pilha * p) {
  return p->qtd_esquerda == 0;
}

int empty2(pilha * p) {
  return p->qtd_direita == 0;
}

void mostrar_tudo(pilha * p) {
  int i;
  for (i = 0; i < p->tamTotal; i++)
    printf("%d ", p->vetor[i]);
  printf("\n");
}


void menu(pilha *p ) {
  int op, retorno, valor;

  do {
    printf("1 - Push 1\n");
    printf("2 - Push 2\n");
    printf("3 - POP 1\n");
    printf("4 - POP 2\n");
    printf("5 - Mostrar tudo\n");
    printf("0 - sair\n");
    scanf("%d", &op);

    switch (op) {
      case 1:
        scanf("%d", &valor);
        retorno = push1(p, valor);
        if (retorno)
          printf("Valor %d inserido na pilha 1\n", valor);
        else
          printf("Não há mais espaço!\n");
        break;
      case 2:
        scanf("%d", &valor);
        retorno = push2(p, valor);
        if (retorno)
          printf("Valor %d inserido na pilha 2\n", valor);
        else
          printf("Não há mais espaço!\n");
        break;
      case 3:
        if (empty1(p))
          printf("Pilha 1 vazia\n");
        else {
          retorno = pop1(p);
          printf("POP1: %d\n", retorno);
        }
        break;
      case 4:
        if (empty2(p))
          printf("Pilha 2 vazia\n");
        else {
          retorno = pop2(p);
          printf("POP2: %d\n", retorno);
        }
        break;
      case 5:
        printf("Mostrando\n");
        mostrar_tudo(p);
        break;
      case 0:
        break;
      default:
        printf("opcao invalida\n");
        break;
    }

  }while(op);
}
