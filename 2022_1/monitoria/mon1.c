#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define NUM_THREADS 4
 
int calcula_divisao(int a, int b);
int num_primo(int numero);
 
int main(int argc, char **argv){

  int threads = argc >= 2 ? atoi(argv[1]) : 4;

    double t1, t2;
    int qtd_num, i;
    int soma=0, count=0;
    omp_set_num_threads(threads);

    printf("%d threads\n", threads);
    
    // printf("Digite a quantidade de numeros: ");
    scanf("%d", &qtd_num);
    
    int vet[qtd_num];
    
    //recebe os nums do vetor
    for(i=0; i<qtd_num; i++){
        // printf("numero no indice %d: ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");

    t1 = omp_get_wtime();

    //printa o vetor e chama a funcao de primos
    #pragma omp parallel for schedule(dynamic, 1)
    for(i=0; i<qtd_num; i++){
        if(num_primo(vet[i])==1){
            printf("%d ", vet[i]);
            soma += vet[i];
            count++;
        }       
    }

    printf("\nQuantidade de numeros primos: %d", count);
    printf("\nSoma dos numeros primos: %d\n", soma);

    t2 = omp_get_wtime();
    printf("\n\nTempo gasto: %lf\n",t2-t1);

    return 0;
}
 
int calcula_divisao(int a, int b){
    for(int i=0; i<10000; i++){
        for (int j=0; j<10000; j++){
            int k=1;
        }
    }
    
    if (a%b==0){
        return 1; //divisivel
    } else {
        return 0; //nÃ£o divisivel
    }
}
 
int num_primo(int numero){
    int i, qtd_divisores=0;
        
    for(i = 1; i <= numero; i++) {
        if (calcula_divisao(numero, i)) {
            qtd_divisores++;
        }
    }
    
    if (qtd_divisores == 2) {
        return 1;
    } else {
        return 0;
    }
}
