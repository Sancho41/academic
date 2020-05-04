#include <stdio.h>
#include <stdlib.h>

void append(int *vetor, int *tam, int valor)
{
  ++*tam;
  vetor = (int *)realloc(vetor, sizeof(int) * (*tam));
  vetor[*tam - 1] = valor;
}

int inverte(int n)
{
  int r = 0;
  while (n)
  {
    r = r * 10;
    r = r + n % 10;
    n = n / 10;
  }
  return r;
}

int caralho(int *vetor, int tam, int qtd, int target)
{
  printf("%d\n", vetor[0]);
  int *j = NULL;
  int i, invertido, somado;
  int w = 0;
  int valor;

  for (i = 0; i < tam; i++)
  {
    valor = vetor[i];

    invertido = inverte(valor);
    somado = valor + 1;

    if (somado == target || invertido == target)
      return qtd;

    if (somado != valor)
    {
      append(j, &w, somado);
    }
    if (invertido != valor)
    {
      append(j, &w, invertido);
    }
  }
  vetor = j;
  return caralho(vetor, w, qtd + 1, target);
}

int main()
{
  int a, b, d;

  scanf("%d", &d);

  while (d--)
  {
    scanf("%d%d", &a, &b);

    int *vetor = (int *)malloc(sizeof(int));
    vetor[0] = a;
    printf("%d\n", caralho(vetor, 1, 1, b));
  }

  return 0;
}
