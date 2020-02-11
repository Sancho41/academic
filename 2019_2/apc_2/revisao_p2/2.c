#include <stdio.h>
#include <stdlib.h>

int * intercala(int * vet1, int tam1, int * vet2, int tam2);

int main() {

    int *vet1, *vet2;
    int tam1, tam2;
    int i;
    int * new_vet;

    printf("Digite os tamanhos separados por espaco: ");
    scanf("%d %d", &tam1, &tam2);

    vet1 = (int*)malloc(sizeof(int) * tam1);
    vet2 = (int*)malloc(sizeof(int) * tam2);

    printf("Digite os valores do primeiro vetor:\n");
    for (i = 0; i < tam1; i++)
        scanf("%d", &vet1[i]);

    printf("Digite os valores do segund vetor:\n");
    for (i = 0; i < tam2; i++)
        scanf("%d", &vet2[i]);

    new_vet = intercala(vet1, tam1, vet2, tam2);

    printf("O novo vetor é:\n");
    for (i = 0; i < tam1 + tam2; i++)
        printf("%d ", new_vet[i]);
    
    printf("\n");

    return 0;
}

int * intercala(int * vet1, int tam1, int * vet2, int tam2){

    int i, j;
    int maior;
    int * new_vet;

    new_vet = (int*)malloc(sizeof(int) * (tam1 + tam2));

    maior = tam1 > tam2 ? tam1 : tam2;

    j = 0;
    for (i = 0; i < maior; i++){
        if (j += i < tam1)
            new_vet[j - 1] = vet1[i];

        if (j += i < tam2)
            new_vet[j - 1] = vet2[i];
    }

    return new_vet;
}