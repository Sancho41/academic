/*
    Exercício inicia na linha 196
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
int remover_registro(lista * l, int x);
void menu (lista * l);
void mostrar_reverso(lista * l, registro * ultimo);
lista ** separa_lista(lista * l);

int main () {

    lista * l1, ** vetor;
    l1 = aloca_lista();
    menu(l1);

    vetor = separa_lista(l1);

    printf("Lista original:\n");
    mostrar(l1);
    printf("Primeiro vetor:\n");

    mostrar(vetor[0]);
    printf("Segundo vetor:\n");
    mostrar(vetor[1]);

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
        printf("Nao existem elementos\n");
    else {
        aux = l->inicio;
        while (aux != NULL){
            printf("valor = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_reverso(lista * l, registro * ultimo){
    if (ultimo == NULL)
        ultimo = l->inicio;
    
    if (ultimo->prox != NULL)
        mostrar_reverso(l, ultimo->prox);
    
    printf("valor reverso: %d\n", ultimo->valor);
}

int remover_registro(lista * l, int x){
    registro * aux, * ant = NULL;
    aux = l->inicio;
    while(aux != NULL){
        if (aux->valor == x){
            if (ant == NULL){
                l->inicio = aux->prox;
                return 1;
            }
            ant->prox = aux->prox;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }
    return 0;
}

void menu (lista * l){
    int op, numero, retorno;
    registro * busca;
    
    do {
        printf("==================\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar\n");
        printf("2 - Buscar\n");
        printf("3 - Deletar\n");
        printf("4 - Mostrar\n");
        printf("5 - Mostrar reverso\n");
        printf("6 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um número para adicionar a lista: ");
                scanf("%d", &numero);
                incluir(l, numero);
                printf("Numero %d adicionado na lista.\n", numero);
            break;
            case 2:
                printf("Digite o numero que deseja procurar: ");
                scanf("%d", &numero);
                busca = procurar(l, numero);
                if (busca)
                    printf("Numero %d encontrado\n", numero);
                else printf("Numero %d nao encontrado\n", numero);
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
            case 5:
                printf("Mostrando lista reverso:\n");
                mostrar_reverso(l, NULL);
            break;
            case 6:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida\n");
            break;
        }

    } while (op != 6);
}

/* Exercício começa aqui */

lista ** separa_lista(lista * l){
    lista ** vetor;
    vetor = (lista**)malloc(2 * sizeof(lista*));
    int i;

    for (i = 0; i < 2; i++)
        vetor[i] = aloca_lista();

    registro * aux;
    aux = l->inicio;

    while (aux != NULL){
        if (aux->valor % 2 == 0)
            incluir(vetor[0], aux->valor);
        else incluir(vetor[1], aux->valor);

        aux = aux->prox;
    }

    return vetor;
}