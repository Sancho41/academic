/*
    Exercício inicia na linha 200
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
int conta_quantidade(lista * l);
void remove_primos(lista * l);
int verifica_primo (int n);

int main () {

    lista * l1;
    l1 = aloca_lista();
    
    menu(l1);

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
        printf("6 - Conta a quantidade de elementos\n");
        printf("7 - Remove primos\n");
        printf("0 - Sair\n");
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
                retorno = conta_quantidade(l);
                printf("Quantidade de elementos: %d\n", retorno);
            break;
            case 7:
                printf("Removendo primos da lista\n");
                remove_primos(l);
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

int conta_quantidade (lista * l) {
    registro * aux = l->inicio;
    int contador = 0;

    while(aux != NULL){
        aux = aux->prox;
        contador++;
    }

    return contador;
}

void remove_primos(lista * l){
    registro * aux, * prox;
    aux = l->inicio;
    while(aux != NULL) {
        prox = aux->prox;
        if (verifica_primo(aux->valor))
            remover_registro(l, aux->valor);
        aux = prox;
    }
}

int verifica_primo (int n) {
    int i;

    if (n == 1) return 0;
    if (n < 0) n = n * (-1);

    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}