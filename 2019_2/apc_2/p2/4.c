// Construa uma função que:

// receba como parâmetro apenas 1 caractere L
// retorne 1 caso L seja uma vogal.
// retorne 2 caso L seja uma consoante.


// Na sua função principal:



// Solicite ao usuário seu nome e armazene em um vetor de nome A;
// Solicite ao usuário seu sobrenome e armazene em um vetor B:
// Concatene o nome com o sobrenome mantendo sua ordem original ( nome depois sobrenome ).
// Percorra o nome completo do usuário e utilizando a função criada diga se a quantidade de vogais é um número primo.
// Percorra o nome completo do usuário e utilizando a função criada diga se a quantidade de consoantes é um número par.
// Mostre o nome completo do usuário de trás pra frente
// Crie um arquivo chamado "quem_estudou_passou.txt" e dentro desse arquivo coloque o nome completo do usuário.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vogal(char letra);
int primo(int n);

int main()
{

    char *nome, *sobrenome, input[255], *nome_completo;
    int tam_nome, tam_sobrenome, tam_nome_completo;
    int qtd_vogais = 0, i;
    FILE *file;

    printf("Digite seu primeiro nome (ate 255 caracteres):\n");
    scanf("%s", input);
    tam_nome = strlen(input);
    nome = (char *)malloc(sizeof(char) * tam_nome);
    strcpy(nome, input);

    printf("Digite seu sobrenome (ate 255 caracteres):\n");
    scanf("%s", input);
    tam_sobrenome = strlen(input);
    sobrenome = (char *)malloc(sizeof(char) * tam_sobrenome);
    strcpy(sobrenome, input);

    tam_nome_completo = (tam_nome + tam_sobrenome + 1);

    nome_completo = (char *)malloc(sizeof(char) * tam_nome_completo);
    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);

    for (i = 0; i < tam_nome_completo; i++)
        qtd_vogais += vogal(nome_completo[i]) == 1;

    if (primo(qtd_vogais))
        printf("\nA quantidade de vogais EH um numero primo.");
    else
        printf("\nA quantidade de vogais NAO EH um numero primo.");

    if ((tam_nome_completo - qtd_vogais - 1) % 2 == 0)
        printf("\nA quantidade de consoantes EH PAR.");
    else
        printf("\nA quantidade de consoantes EH IMPAR.");

    printf("\n");

    for (i = tam_nome_completo - 1; i >= 0; i--)
        printf("%c", nome_completo[i]);

    printf("\n");

    file = fopen("quem_estudou_passou.txt", "w");
    fprintf(file, "%s", nome_completo);
    fclose(file);

    return 0;
}

int vogal(char letra)
{
    char vogais[10] = "aeiouAEIOU";
    int i;
    for (i = 0; i < 10; i++)
        if (vogais[i] == letra)
            return 1;
    return 2;
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