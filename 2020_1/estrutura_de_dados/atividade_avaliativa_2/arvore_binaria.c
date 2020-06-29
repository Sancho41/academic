/**
 * Atividade avalitiva P2
 * 
 * Autor: Gabriel Sancho
 * Matrícula: 1712130049
 * Curso: Ciência da computação
 * Descrição do programa: Este programa recebe como entrada a quantidade
 * de elementos para serem colocados em uma árvore, e, posteriormente, 
 * recebe uma quantidade de números, definidos pelo usuário, fazendo uma
 * busca na árvore desse número.
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura de uma árvore binária, tem como atributos um vetor e o tamanho
 * deste vetor.
*/
typedef struct ARVORE
{
  int *vetor;
  long long int tamanho_vetor;
} ARVORE;

ARVORE *inicializa_arvore(int quantidade);
void insere(ARVORE *arvore, int numero, int elemento);
int procura(ARVORE *arvore, int numero, int elemento);
int power(int base, int exp);

/**
 * Função principal.
*/
int main()
{
  int i;
  int quantidade;
  int numero;
  ARVORE *arvore;

  // Recebe a quantidade de elementos a serem inseridos.
  printf("Digite a quantidade de elementos da árvore:\n");
  scanf("%d", &quantidade);

  // Inicializa a árvore com base na quantidade de elementos.
  arvore = inicializa_arvore(quantidade);

  // Recebe os números da árvore.
  printf("Digite os números da árvore (positivos):\n");
  for (i = 0; i < quantidade; i++)
  {
    scanf("%d", &numero);
    // Vai inserindo número por número na árvore.
    insere(arvore, numero, 0);
  }

  numero = 0;

  // Inicia a busca dos números na árvore.
  do
  {
    printf("Digite um número para verficar se está contido na árvore");
    printf(" (Digite -1 para sair)\n");
    scanf("%d", &numero);
    if (numero != -1)

      // Faz a busca do número na árvore.
      if (procura(arvore, numero, 0))
      {
        printf("Número %d foi encontrado na árvore!\n", numero);
      }
      else
      {
        printf("Número %d não encontrado na arvore!\n", numero);
      }

    printf("\n");
  } while (numero != -1);

  return 0;
}

/**
 * Função que inicializa uma nova árvore binária.
*/
ARVORE *inicializa_arvore(int quantidade)
{
  int i;

  ARVORE *arvore;
  arvore = (ARVORE *)malloc(sizeof(ARVORE));

  // Define o tamanho do vetor, com base na quantidade de elementos.
  // Por não se tratar de uma arvore AVL, se faz necessário definir um tamanho
  // mínimo do vetor para que não tenha problemas de acesso de vetor.
  // A quantidade máxima é definda pela quantidade máxima de níveis que a árvore
  // pode ter. Como por exemplo, todas as entradas irão para o lado direito,
  // criando uma quantidade de níveis igual a quantidade de entradas.
  arvore->tamanho_vetor = power(2, quantidade) - 1;

  arvore->vetor = (int *)malloc(sizeof(int) * arvore->tamanho_vetor);

  // Inicializa o vetor com -1.
  for (i = 0; i < arvore->tamanho_vetor; i++)
    arvore->vetor[i] = -1;

  return arvore;
}

/**
 * Função que insere um novo elemento em uma árvore.
 * Obs: Trata-se de uma insersão de forma recursiva.
*/
void insere(ARVORE *arvore, int numero, int elemento)
{
  int esquerda = elemento * 2 + 1;
  int direita = elemento * 2 + 2;

  // Verificação para evitar acesso fora do vetor.
  if (elemento >= arvore->tamanho_vetor)
  {
    return;
  }

  // Verifica se o espaço atual está vazio, se estiver o número é adicionado
  // neste espaço.
  if (arvore->vetor[elemento] == -1)
  {
    arvore->vetor[elemento] = numero;
  }
  else
  {
    // Se não estiver vazio, é verificado se o número é maior ou menor.
    // Se for maior será feito a movimentação para o lado direto,
    // se for menor será feito a moviemntação para o lado esquerdo.
    if (numero > arvore->vetor[elemento])
    {
      insere(arvore, numero, direita);
    }
    else
    {
      insere(arvore, numero, esquerda);
    }
  }
}

/**
 * Função que procura um elemento em uma árvore.
 * Obs: A procura é feita de forma recursiva.
*/
int procura(ARVORE *arvore, int numero, int elemento)
{
  int *vetor = arvore->vetor;
  int esquerda = elemento * 2 + 1;
  int direita = elemento * 2 + 2;

  // Verificação para evitar acessos fora do vetor.
  if (elemento < arvore->tamanho_vetor)
  {
    // Verifica se o elemento está preenchido.
    if (vetor[elemento] != -1)
    {

      // Verifica se o elemento corresponde ao número.
      if (numero == vetor[elemento])
      {
        return 1;
      }
      // Se o numero for menor que o elemento, procura pela esquerda
      else if (numero < vetor[elemento])
      {
        return procura(arvore, numero, esquerda);
      }
      // Se o numero for maior que o elemento, procura pela direita
      else
      {
        return procura(arvore, numero, direita);
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}

/**
 * Função auxiliar para cálculo de potência.
*/
int power(int base, int exp)
{
  if (exp < 0)
    return -1;

  int result = 1;
  while (exp)
  {
    if (exp & 1)
      result *= base;
    exp >>= 1;
    base *= base;
  }

  return result;
}
