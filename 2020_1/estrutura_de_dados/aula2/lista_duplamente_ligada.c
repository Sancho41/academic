#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}lista;

typedef struct registro {
    int valor;
    struct registro * prox;
    struct registro * ant;
}registro;

lista * aloca_lista();
registro * aloca_registro();

int main () {
    
    return 0;
}

lista * aloca_lista(){
    struct lista * novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->fim = NULL;
    novo->qtd = 0;
    return novo;
}

registro * aloca_registro(){
    struct registro * novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void incluir_inicio(lista * l, int x){
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0){
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
}

void incluir_fim(lista * l, int x) {
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0){
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->ant = novo;
        novo->prox = l->fim;
        l->inicio = novo;
    }
    l->qtd++;
}

int remover_registro(lista * l, int x) {

    registro * aux, * de_tras, * da_frente;
    aux = l->inicio;

    if (l->qtd == 0) return 0;

    while(aux != NULL){
        if (aux->valor == x){

            de_tras = aux->ant;
            da_frente = aux->prox;

            if (de_tras == NULL)
                l->inicio = da_frente
            else de_tras->prox = da_frente;
            
            if (da_frente == NULL)
                l->fim = de_tras;
            else da_frente->ant = de_tras;

            free(aux);
            return 1;
        }
    }

    return 0;
}