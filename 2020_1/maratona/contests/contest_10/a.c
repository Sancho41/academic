#include <stdio.h>

int main()
{
  int qtd, i;

  int qtd1 = 0;
  int qtd2 = 0;

  scanf("%d", &qtd);

  int vet[qtd];

  for (i = 0; i < qtd; i++)
  {
    scanf("%d", &vet[i]);
    if (vet[i] == 1)
      qtd1++;
    else
      qtd2++;
  }

  for (i = 0; i < qtd; i++)
  {
    if (vet[i] == 1)
      qtd1--;
    else
      qtd2--;

    if (qtd1 == 0 || qtd2 == 0)
    {
      printf("%d\n", qtd - qtd1 - qtd2);
      break;
    }
  }

  return 0;
}