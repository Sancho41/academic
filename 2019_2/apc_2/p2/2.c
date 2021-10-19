// Construa uma função que:

// receba por parâmetro:
//  2 vetores A[ ] e B[ ] de números inteiros;
// um número inteiro N que representa o tamanho de cada um dos vetores;
// o endereço de uma variável inteira ( ponteiro Ex: int *qtd) que irá apontar para um espaço de memória que conterá o tamanho do vetor que será retornado pela função.
// calcule quantos elementos pares existem no primeiro vetor e guarde em uma variável de nome qtd_pares_1;
// calcule quantos elementos pares existem no segundo vetor e guarde em uma variável de nome qtd_pares_2;
// aloque dinamicamente um vetor de tamanho K, onde K = qtd_pares_1 + qtd_pares2;
// preencha o vetor alocado com todos os números pares do primeiro vetor seguido de todos números pares do segundo vetor.
// atribua como conteúdo da variável referenciada pelo ponteiro *qtd o valor de K.
// retorne o vetor alocado.

// EX: Se os 2 vetores recebidos forem:
// Vetor 1 = {1,2,3,4,5}
// Vetor 2 = {6,7,8,9,10}

// Sua função deve retornar:

// Vetor 3 = {2,4,6,8,10}.

// Na sua função principal:

// leia um valor inteiro positivos do usuário e armazene em uma variável N,
// aloque dinamicamente 2 vetores de tamanho N.
// preencha os 2 vetores com números digitados pelo usuário.
// invoque a função criada passando como parâmetro:
// Os 2 vetores alocados;
// N
// o endereço de uma variável inteira declarada para receber como conteúdo o tamanho do vetor que será retornado.
// mostre o conteúdo do vetor retornado pela função.

#include <stdio.h>
#include <stdlib.h>

int *cachorrao(int *a, int *b, int n, int *qtd);

int main()
{

    int *a, *b, *c;
    int i, qtd, n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);

    printf("Digite os valores do vetor 1:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Digite os valores do vetor 2:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    c = cachorrao(a, b, n, &qtd);

    printf("Novo vetor:\n");
    for (i = 0; i < qtd; i++)
        printf("%d ", c[i]);

    printf("\n");

    return 0;
}

int *cachorrao(int *a, int *b, int n, int *qtd)
{
    int qtd_pares_1 = 0, qtd_pares_2 = 0;
    int *vetor_pares;
    int i, j;

    for (i = 0; i < n; i++)
    {
        qtd_pares_1 += a[i] % 2 == 0;
        qtd_pares_2 += b[i] % 2 == 0;
    }

    vetor_pares = (int *)malloc(sizeof(int) * (qtd_pares_1 + qtd_pares_2));

    j = 0;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            vetor_pares[j++] = a[i];

    for (i = 0; i < n; i++)
        if (b[i] % 2 == 0)
            vetor_pares[j++] = b[i];

    *qtd = qtd_pares_1 + qtd_pares_2;

    return vetor_pares;
}