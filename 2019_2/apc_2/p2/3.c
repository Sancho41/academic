// Em matemática, uma conjectura é uma proposição que muitos matemáticos acreditam ser verdadeira, com base em presunções, evidências, pressentimentos, hipóteses, porém ainda não conseguiram prová-la.
// A famosa conjectura de Goldbach é um dos problemas mais antigos não resolvidos da matemática. Foi proposta no dia 7 de junho de 1742 pelo matemático prussiano Christian Goldbach, em uma carta escrita para Leonhard Euler.
// A conjectura diz o seguinte:
// Todo número par maior que 2 pode ser representado pela soma de dois números primos.
// Por exemplo:

// 4 = 2+2
// 6 = 3+3
// 8 = 3+5
// 10 = 3+7 = 5+5
// 12 = 5+7
// 14 = 7+7
// 16 = 5+11
// 18 = 7+11
// 20 = 7+13

// Faça um programa que :

// receba um número N do usuário.
// caso N seja ímpar mostre a mensagem: "número ímpar" e solicite outro número ao usuário.
// caso N seja par mostre na tela 2 valores primos que somados seja igual a N.

#include <stdio.h>

int primo(int n);
int main()
{

    int n, sum = 0, n1 = 0, n2 = 0;

    printf("Digite um numero: ");
    scanf("%d", &n);

    while (n % 2 != 0)
    {
        printf("Digite um numero par: ");
        scanf("%d", &n);
    }

    for (n1 = n; n1 >= 1; n1--)
    {
        if (!primo(n1))
            continue;

        n2 = n - n1;
        if (primo(n2))
            break;
    }

    printf("%d %d\n", n1, n2);

    return 0;
}

int primo(int n)
{
    int i;
    if (n == 0 || n == 1)
        return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
