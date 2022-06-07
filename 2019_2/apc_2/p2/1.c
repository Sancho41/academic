// Construa uma função que

// receba o valor de 2 números inteiros X e Y que correspondem a coordenada de um ponto em um plano cartesiano.
// Sua função deve retornar:
// 1 caso a coordenada represente um ponto que pertence ao primeiro quadrante.
// 2 caso a coordenada represente um ponto que pertence ao segundo quadrante.
// 3 caso a coordenada represente um ponto que pertence ao terceiro quadrante.
// 4 caso a coordenada represente um ponto que pertence ao quarto quadrante.
// 5 caso a coordenada esteja sobre o eixo x.
// 6 caso a coordenada esteja sobre o eixo y.
// 7 caso a coordenada seja (0,0).


// Na sua função principal:

// solicite ao usuário um número N inteiro positivo,
// aloque dinamicamente em memória o espaço necessário para armazenar N coordenadas ( cada coordenada tem 2 valores: X e Y).
// solicite ao usuário que preencha as N coordenadas (X,Y)
// utilizando a função criada, diga em qual quadrante cada uma das coordenadas está.

#include <stdio.h>
#include <stdlib.h>

int quadrante(int x, int y);

int main()
{
    int n, *x, *y, i, q;

    printf("Digite a quantidade de verificacoes: ");
    scanf("%d", &n);

    x = (int *)malloc(sizeof(int) * n);
    y = (int *)malloc(sizeof(int) * n);

    printf("Digite o um x e y por linha:\n");

    for (i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i < n; i++)
    {

        printf("(%d, %d) = ", x[i], y[i]);

        q = quadrante(x[i], y[i]);

        switch (q)
        {
        case -2:
            printf("Eixo do X");
            break;
        case -1:
            printf("Eixo do Y");
            break;
        case 0:
            printf("Centro");
            break;
        default:
            printf("Quadrante %d", q);
            break;
        }

        printf("\n");
    }

    return 0;
}

int quadrante(int x, int y)
{
    int pos_x, pos_y;
    pos_x = x > 0;
    pos_y = y > 0;

    if (x == 0 && y == 0)
        return 0;

    if (x == 0 || y == 0)
    {
        if (x == 0)
            return -1;
        return -2;
    }
    if (pos_x)
    {
        if (pos_y)
            return 1;
        return 4;
    }

    if (pos_y)
        return 2;
    return 3;
}