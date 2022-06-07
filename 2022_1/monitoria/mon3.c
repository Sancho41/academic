#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct cartas
{

  int fila[TAM];
  int qtd;
  int inicio;
  int fim;

} cartas;

void push(cartas *a, int numero);
int pop(cartas *a);
int resolve(int numero);

int main()
{
  int numero;

  scanf("%d", &numero);

  while (numero != 0)
  {
    resolve(numero);

    scanf("%d", &numero);
  }
}

int resolve(int numero)
{
  cartas a;

  a.inicio = 0;
  a.fim = 0;
  a.qtd = 0;

  if (numero < 50)
  {
    for (int i = 1; i <= numero; i++)
    {
      push(&a, i);
    }
  }

  if (numero == 0)
  {
    return 0;
  }
  else
  {
    printf("Discarded cards: ");

    int carta_removida, carta_base;

    do
    {
      carta_removida = pop(&a);
      printf("%d", carta_removida);
      carta_base = pop(&a);
      push(&a, carta_base);
      if (a.qtd >= 2)
        printf(", ");
    } while (a.qtd > 1);

    printf("\nRemaining card: %d\n", a.fila[a.inicio]);

    pop(&a);
  }
}

// Pra alterar a struct que foi declarada o parâmetro das funções push e pop precisa ser o endereço dessa struct
/*Caso seja a própria struct, uma cópia será criada e nada será incluido ou retirado da struct verdadeira, ocasionando
a impressão de lixos de memória*/

void push(cartas *a, int numero)
{

  if (a->qtd != TAM)
  {
    a->fila[a->fim] = numero;
    a->qtd++;
    a->fim = (a->inicio + a->qtd) % TAM;
  }
}

int pop(cartas *a)
{
  int carta_removida;
  if (a->qtd != 0)
  {
    carta_removida = a->fila[a->inicio];
    a->fila[a->inicio] = 0;
    a->inicio = (a->inicio + 1) % TAM;
    a->qtd--;
  }

  return carta_removida;
}