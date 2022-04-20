#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct cartas{

    int fila[TAM];
    int qtd;
    int inicio;
    int fim;

}cartas;

void push(cartas *a, int numero);
int pop(cartas *a);

int main(){     

    int numero;
    cartas a;

    int *valores;
    valores = (int*)malloc(numero * sizeof(int));


   do{

        scanf("%d", &numero);

        a.inicio = 0;
        a.fim = 0;
        a.qtd = 0;

        if(numero < 50){
            int i;
            for(i = 1; i <= numero; i++){
                push(&a, i);
            }
        }

        if(numero == 0){
            return 0;
        }else{
            printf("Discarded cards:");
            
                int carta_removida, carta_base;

                do{
                    carta_removida = pop(&a);
                    printf(" %d,", carta_removida);
                    carta_base = pop(&a);
                    push(&a, carta_base);
                    
                }while(a.qtd > 2);

                if(a.qtd = 3){
                    carta_removida = pop(&a);
                    printf(" %d", carta_removida);
                }

            printf("\nRemaining card: %d\n", a.fila[a.inicio]);

            pop(&a);
        }
    }while(numero != 0);
    
    return 0;
}

void push(cartas *a, int numero){

    if(a->qtd != TAM){
        a->fila[a->fim] = numero;
        a->qtd++;
        a->fim = (a->inicio + a->qtd) % TAM;
    }

}

int pop(cartas *a){
    int carta_removida;
    if(a->qtd != 0){
        carta_removida = a->fila[a->inicio];
        a->fila[a->inicio] = 0;
        a->inicio = (a->inicio + 1) % TAM;
        a->qtd--;
    }

    return carta_removida;
}