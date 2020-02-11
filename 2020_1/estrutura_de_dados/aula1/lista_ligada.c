/*
    Dia 10/02 - Lista Ligadas
    Um elemento tem uma referência para próximo elemento
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro * inicio;
}lista;

typedef struct registro {
    int valor;
    struct registro * prox;
}registro;


void mostrar(lista * l);
lista * aloca_lista();
registro * aloca_registro();
void incluir(lista * l,int x);

int main () {

    lista * l1;
    l1 = aloca_lista();

    incluir(l1, 1);
    incluir(l1, 2);
    incluir(l1, 3);
    mostrar(l1);

    return 0;
}

lista * aloca_lista(){
    struct lista * novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->qtd = 0;
    return novo;
}

registro * aloca_registro(){
    struct registro * novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir(lista * l, int x){
    // Cria novo registro
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    // Adiciona novo registro na
    if (l->qtd == 0)
        l->inicio = novo;
    else {
        registro * aux = l->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar(lista * l){
    registro * aux;
    if (l->inicio == NULL)
        printf("\n Nao existem elementos");
    else {
        aux = l->inicio;
        while (aux != NULL){
            printf("valor = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

