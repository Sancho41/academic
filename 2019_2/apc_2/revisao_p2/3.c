#include <stdio.h>
#include <stdlib.h>

int *valores_entre(int *v, int n, int min, int max, int *qtd);

int main()
{
    int tam, min, max;
    int *vetor, *new_vet, tam_new_vet;
    int i;

    printf("\nDigite o tamanho, o numero max e min separado por espacos: ");
    scanf("%d %d %d", &tam, &min, &max);

    vetor = (int *)malloc(sizeof(int) * tam);

    for (i = 0; i < tam; i++)
    {
        printf("Digite o numero da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    new_vet = valores_entre(vetor, tam, min, max, &tam_new_vet);

    if (new_vet)
    {
        printf("\nNovo vetor:\n");
        for (i = 0; i < tam_new_vet; i++)
            printf("%d ", new_vet[i]);
    }
    else
        printf("Não existem valores entre os parametros recebidos!");

    printf("\n");

    return 0;
}

int *valores_entre(int *v, int n, int min, int max, int *qtd)
{
    int qnt_entre = 0;
    int i, j;
    int *new_vet;

    for (i = 0; i < n; i++)
        qnt_entre += v[i] > min && v[i] < max;

    if (qnt_entre > 0)
        new_vet = (int *)malloc(sizeof(int) * qnt_entre);

    j = 0;
    for (i = 0; i < n; i++)
        if (v[i] > min && v[i] < max)
            new_vet[j++] = v[i];

    *qtd = qnt_entre;

    return qnt_entre > 0 ? new_vet : NULL;
}
