#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pilha[1000];
char mina[1000];
int topo = 0;

int procura_diamantes(char *mina);
void push(char mina);
int pop();
int empty();

int main(){

    int N, i;
    scanf("%d", &N);

    int diamantes[N];
    
    for(i = 0; i < N; i++){
        scanf("%s", mina);
        diamantes[i] = procura_diamantes(mina);
        topo = 0;
    }

    for(i = 0; i < N; i++){
        printf("%d\n", diamantes[i]);
    }


    return 0;
}


void push(char mina){
    pilha[topo] = mina;
    topo++;
}

int pop(){
    if(empty()){
        return -1;
    }else{
        topo--;
        return pilha[topo];
    }
}

int empty(){
    if(topo == 0){
        return 1;
    }else{
        return 0;
    }

}

int procura_diamantes(char *mina){
    int i;
    int qtd_diamantes = 0;
    int tam = strlen(mina);
    char result;

    for(i = 0; i < tam; i++){
        if(mina[i] == '<'){
            push(mina[i]);
        }
        if(mina[i] == '>'){
            result = pop();
            if (result == '<')
              qtd_diamantes++;     
        }
    }
    return qtd_diamantes;
}