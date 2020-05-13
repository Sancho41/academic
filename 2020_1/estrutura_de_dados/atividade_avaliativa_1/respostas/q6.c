
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
void push(fila * f, int valor);
int pop(fila * f);

int main () {

  int input, i, last;
  fila * f, * d;

  while(1) {
    scanf("%d", &input);

    if (!input)
      break;
    
    f = aloca_fila();
    d = aloca_fila();

    for (i = 1; i <= input; i++ )
      push(f, i);

    while (f->qtd >= 2) {
      push(d, pop(f));
      push(f, pop(f));
    }

    printf("Discarded cards: ");
    while (d->qtd > 1) {
      printf("%d, ", pop(d));
    }
    
    last =  pop(d);

    if (last != -1)
      printf("%d\n", last);
    else
      printf("\n");

    printf("Remaining card: %d\n", pop(f));
  }

  return 0;
}

fila * aloca_fila() {
  fila * f = (fila*)malloc(sizeof(fila));
  f->qtd = 0;
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

void push(fila * f, int valor) {
  registro * r = (registro*)malloc(sizeof(registro));
  r->prox = NULL;
  r->valor = valor;

  if (f->qtd == 0)
    f->inicio = r;
  else
    f->fim->prox = r;

  f->fim = r;
  f->qtd++;
}

int pop(fila * f) {
  registro * aux;
  int valor = -1;

  aux = f->inicio;

  if (aux){
    valor = aux->valor;
    f->inicio = f->inicio->prox;
    f->qtd--;
    free(aux);
  }
  return valor;
}
