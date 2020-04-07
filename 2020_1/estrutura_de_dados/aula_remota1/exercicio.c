/*
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    struct registro * topo;
    int qtd;
}pilha;

typedef struct registro {
    int valor;
    struct registro * ant;
}registro;

struct registro * aloca_registro();
void push(pilha * p, int valor);
int pop(pilha * p);
int empty(pilha * p);

int main () {
    char a[1000];
    int i, j, qtd, diamonds;

    scanf("%d", &qtd);

    struct pilha * p = (pilha*)malloc(sizeof(struct pilha));
    p->topo = NULL;
    p->qtd = 0;

    for (i = 0; i < qtd; i++){

        scanf("%s", a);
        diamonds = 0;
        for (j = 0; j < strlen(a); j++){

            if (a[j] == '<') push(p, 1);
            else if (a[j] == '>' && pop(p)){
               
                diamonds++;
            }

        }
        printf("%d\n", diamonds);

        p->topo = NULL;
        p->qtd = 0;
    }

    return 0;
}

struct registro * aloca_registro() {
    struct registro * r;
    r = (registro*)malloc(sizeof(struct registro));
    r->valor = 0;
    r->ant = NULL;
}

void push(pilha * p, int valor) {
    struct registro * r = aloca_registro();
    r->valor = valor;
    r->ant = p->topo;
    p->topo = r;
    p->qtd++;
}

int pop(pilha * p) {
    if (empty(p)) return 0;
    struct registro * topo = p->topo;
    int valor = topo->valor;
    p->topo = topo->ant;
    free(topo);
    p->qtd--;
    return valor;
}

int empty(pilha * p) {
    return p->qtd == 0;
}