/*
    Exercício inicia na linha 182
*/
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
void concatena_listas(lista * l1, lista * l2);
void mostrar(lista * l);
void menu (lista * l);

int main () {
    lista * l1, * l2;
    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("Preencha a primeira lista:\n");
    menu(l1);
    printf("Preencha a segunda lista:\n");
    menu(l2);
    concatena_listas(l1, l2);
    printf("Listas concatenadas:\n");
    mostrar(l1);
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
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
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
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
}

void mostrar(lista * l){
    registro * aux;
    if (l->inicio == NULL)
        printf("Nao existem elementos\n");
    else {
        aux = l->inicio;
        while (aux != NULL){
            printf("valor = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
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
                l->inicio = da_frente;
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

void menu (lista * l){
    int op, numero, retorno;
    registro * busca;
    
    do {
        printf("==================\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar pelo final\n");
        printf("2 - Adicionar pelo inicio\n");
        printf("3 - Deletar\n");
        printf("4 - Mostrar\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um número para adicionar ao final da lista: ");
                scanf("%d", &numero);
                incluir_fim(l, numero);
                printf("Numero %d adicionado na lista.\n", numero);
            break;
            case 2:
                printf("Digite um número para adicionar ao inicio da lista: ");
                scanf("%d", &numero);
                incluir_inicio(l, numero);
                printf("Numero %d adicionado na lista.\n", numero);
            break;
            case 3:
                printf("Digite o numero que deseja excluir: ");
                scanf("%d", &numero);
                retorno = remover_registro(l, numero);
                if (retorno)
                    printf("Numero %d deletado com sucess\n", numero);
                else printf("Numero %d nao encontrado\n", numero);
            break;
            case 4:
                printf("Mostrando lista:\n");
                mostrar(l);
            break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida\n");
            break;
        }

    } while (op != 0);
}

/* Exercício começa aqui */

void concatena_listas(lista * l1, lista * l2){
    l1->fim->prox = l2->inicio;
    l1->fim = l2->fim;
}