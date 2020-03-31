#include <stdio.h>
#include <stdlib.h>
#define tam 10

int qtd = 0;
int vet[tam];

int main () {
    
}

int push(int x){
    if (!full()){
        vetor[qtd] = x;
        qtd++;
        return 1
    }
    return 0
}

int pop(){
    if (empty())
        return -1;
    return vet[--qtd];
}

int stackpop(){
    return vet[qtd - 1];
}

int empty(){
    return qtd == 0;
}

int full(){
    return qtd == tam;
}