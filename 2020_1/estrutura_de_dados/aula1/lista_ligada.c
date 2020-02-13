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
registro * procurar(lista * l, int x);
void deletar(lista * l, registro * r);

int main () {

    lista * l1;
    l1 = aloca_lista();
    int i;

    printf("Incluindo Itens:\n");

    for (i = 0; i < 10; i++){
        incluir(l1, i);
    }

    printf("Mostrando itens:\n");
    mostrar(l1);
    printf("Procurando item de valor 2:\n");
    registro * a = procurar(l1, 2);
    printf("Deletando item de valor 2:\n");
    deletar(l1, a);
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

    // Adiciona novo registro na lista
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

registro * procurar(lista * l, int x){
    registro * aux;
    if (l->inicio == NULL)
        return NULL;
    else {
        aux = l->inicio;
        while(aux != NULL){
            if (aux->valor == x)
                return aux;
            aux = aux->prox;
        }
        return NULL;
    }
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

void deletar(lista * l, registro * r){
    registro * aux;
    registro * ant;
    aux = l->inicio;
    while(aux != NULL){
        if (aux->prox == r){
            ant = aux;
            aux = aux->prox;
            ant->prox = aux->prox;
            free(aux);
            break;
        }
        aux = aux->prox;
    }
}