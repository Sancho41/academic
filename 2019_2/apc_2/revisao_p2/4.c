#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primo(int n);
int conta_consoante(char *palavra, int tamanho);

int main(void)
{

    char *nome, *sobrenome;
    int tam_nome, tam_sobrenome;
    char input[200];
    int qnt_con_nome;
    int qnt_con_sobrenome;
    FILE * file;
    char vogais[10] = "aeiouAEIOU";
    int i, j, is_vowel;
    int nome_primo, sobrenome_primo;

    printf("Digite seu primeiro nome: ");
    fgets(input, 200, stdin);
    tam_nome = strlen(input) - 1;
    nome = (char *)malloc(sizeof(char) * tam_nome);
    strcpy(nome, input);

    printf("Digite seu sobrenome: ");
    fgets(input, 200, stdin);
    tam_sobrenome = strlen(input) - 1;
    sobrenome = (char *)malloc(sizeof(char) * tam_sobrenome);
    strcpy(sobrenome, input);

    qnt_con_nome = conta_consoante(nome, tam_nome);
    qnt_con_sobrenome = conta_consoante(sobrenome, tam_sobrenome);

    nome_primo = primo(qnt_con_nome);
    sobrenome_primo = primo(qnt_con_sobrenome);

    if (nome_primo)
        printf("O primeiro nome e primo!\n");
    else printf("O primeiro nome nao e primo!\n");

    if (sobrenome_primo)
        printf("O sobrenome e primo!\n");
    else printf("O sobrenome nao e primo!\n");

    
    if (nome_primo && sobrenome_primo)
    {
        file = fopen("todos.txt", "w");
        for (i = 0; i < tam_nome; i++)
        {
            is_vowel = 0;
            for (j = 0; j < 10; j++)
            {
                if (nome[i] == vogais[j])
                {
                    is_vowel = 1;
                }
            }
            if (!is_vowel)
                fprintf(file, "%c", nome[i]);
        }

        fprintf(file, "\n");

        for (i = 0; i < tam_sobrenome; i++)
        {
            is_vowel = 0;
            for (j = 0; j < 10; j++)
            {
                if (sobrenome[i] == vogais[j])
                    is_vowel = 1;
            }

            if (!is_vowel)
                fprintf(file, "%c", sobrenome[i]);
        }

        fclose(file);
    }
    else if (nome_primo && !sobrenome_primo)
    {
        file = fopen("nome.txt", "w");

        for (i = tam_sobrenome - 1; i >= 0; i--)
            fprintf(file, "%c", sobrenome[i]);
        
        fprintf(file, " ");

        for (i = tam_nome - 1; i >= 0; i--)
            fprintf(file, "%c", nome[i]);

        fprintf(file, "\n");

        fclose(file);
    }
    else if (!nome_primo && sobrenome_primo)
    {
        file = fopen("sobrenome.txt", "w");
        fprintf(file, "%s", sobrenome);
        fclose(file);
    }
    else
    {
        file = fopen("nenhum.txt", "w");
        fprintf(file, "Ambas quantidades não são primos.");
        fclose(file);
    }



    return 0;
}

int primo(int n)
{
    if (n <= 1 )
        return 0;
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int conta_consoante(char *palavra, int tamanho)
{
    char vogais[10] = "aeiouAEIOU";
    int i, j;
    int contador = 0;

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < 10; j++)
        {
            contador += palavra[i] == vogais[j];
        }
    }

    return tamanho - contador;
}