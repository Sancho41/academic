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
  int i;
  char * entrada, caractere;

  pilha * p = (pilha*)malloc(sizeof(pilha));
  p->qtd = 0;
  p->inicio = NULL;

  // O 'm' depois do '%' diz para o scanf medir o tamanho da string,
  // alocar a memoria e copiar a string e armazenar o endereço desse lugar
  // na entrada (ele recebe um parametro do tipo **char)

  // O '[^\n]' diz para o scanf ler até encontrar o '\n'
  scanf("%m[^\n]s", &entrada);

  for (i = 0; i < strlen(entrada); i++) {
    caractere = entrada[i];

    if (caractere == '(')
      push(p, '(');
    else if (caractere == ')') {
      if (empty(p) || stackpop(p) != '('){
        printf("está incorreto\n");
        return 0;
      } else 
        pop(p);
    }
  }

  if (empty(p))
    printf("está correto\n");
  else 
    printf("está incorreto\n");
  
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