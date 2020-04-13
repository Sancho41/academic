#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
  int qtd;
  struct registro * inicio;
}pilha;

typedef struct registro {
  char caractere;
  struct registro * prox;
}registro;

void push(pilha * p, char c);
char pop(pilha * p);
int empty(pilha * p);
char stackpop(pilha * p);

int main () {
  int i, tamTotal, tamTeste,metade = 0;
  char * entrada, car;

  pilha * p = (pilha*)malloc(sizeof(pilha));
  p->qtd = 0;
  p->inicio = NULL;

  // O 'm' depois do '%' diz para o scanf medir o tamanho da string,
  // alocar a memoria, copiar a string e armazenar o endereço desse lugar
  // na var entrada (ele recebe um parametro do tipo **char)

  // O '[^\n]' diz para o scanf ler até encontrar o '\n'
  scanf("%m[^\n]s", &entrada);
  tamTotal = strlen(entrada);


  for (i = 0; i < tamTotal; i++) {
    car = entrada[i];

    if (car == ' ')
      continue;

    if (car == 'D') {
      if (!empty(p)){
        printf("inválido\n");
        return 0;
      }
      metade = 0;
      tamTeste = 0;
      p->qtd = 0;
      p->inicio = NULL;
      continue;
    }

    if (car == 'C') {
      metade = 1;
      continue;
    }

    if (!metade)
      push(p, car);
    else {
      if (car != pop(p)){
        printf("inválido\n");
        return 0;
      }
    }
  }

  printf("válido\n");
  
  return 0;
}

void push(pilha * p, char c) {
  registro * r = (registro*)malloc(sizeof(registro));
  r->caractere = c;
  r->prox = NULL;

  r->prox = p->inicio;
  p->inicio = r;
  p->qtd++;
}

char pop(pilha * p) {

  char c = '\0';
  registro * aux;

  if (!empty(p)){
    aux = p->inicio;
    c = aux->caractere;
    p->inicio = aux->prox;
    free(aux);
    p->qtd--;
  }

  return c;
  
}

int empty(pilha * p) {
  return p->qtd == 0;
}

char stackpop(pilha * p) {
  if (!empty(p))
    return p->inicio->caractere;
  return '\0';
}