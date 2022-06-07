/*
    O primeiro elemento que entra é o último que sai.

    Implementando as funções push e pop
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
    int valor;
    struct registro * anterior;
}registro;

typedef struct pilha {
    struct registro * topo;
    int qnt;
}pilha;

int empty(pilha * p);
int pop(pilha * p);
void push(pilha * p, int v);
registro * aloca_registro();
pilha * aloca_pilha();

int main () {

    struct pilha * p;
    p = aloca_pilha();
    int op, valor, retorno;

    do {
        printf("1 - PUSH\n");
        printf("2 - POP\n");
        printf("0 - SAIR\n");
        scanf("%d", &op);

        switch (op) {
            case 0:
                printf("Saindo...\n");
            break;
            case 1:
                scanf("%d", &valor);
                printf("PUSH: %d\n", valor);
                push(p, valor);
            break;
            case 2:
                if (!empty(p)){
                    retorno = pop(p);
                    printf("POP: %d\n", retorno);
                } else printf("Pilha Vazia!\n");
            break;
            default: 
                printf("Opcao invalida\n");
            break;
        }


    } while (op != 0);

    return 0;
}

pilha * aloca_pilha(){
    struct pilha * p;
    p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    p->qnt = 0;
    return p;
}

registro * aloca_registro(){
    struct registro * r;
    r = (registro*)malloc(sizeof(registro));
    r->valor = 0;
    r->anterior = NULL;
    return r;
}

void push(pilha * p, int v) {
    registro * r;
    r = aloca_registro();
    r->valor = v;
    r->anterior = p->topo;
    p->topo = r;
}

int pop(pilha * p) {
    struct registro * topo;
    int valor;
    topo = p->topo;
    valor = topo->valor;
    p->topo = topo->anterior;
    free(topo);
    return valor;
}

int empty(pilha * p) {
    return p->topo == NULL;
}