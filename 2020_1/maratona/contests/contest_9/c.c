#include <stdio.h>
#include <string.h>

int main()
{
  int qtd, i, j;
  char entrada[1000];
  char vogais[10] = "aeiouAEIOU";
  int vog, tam;
  scanf("%d", &qtd);

  while (qtd--)
  {
    scanf("%s", entrada);
    tam = strlen(entrada);
    vog = 0;

    for (i = 0; i < tam; i++)
    {
      for (j = 0; j < 10; j++)
      {
        if (entrada[i] == vogais[j])
        {
          vog++;
          break;
        }
      }
    }

    if (vog && !(tam % 2) && !(tam % vog))
      printf("hahaha\n");
    else
      printf("assim nao po\n");
  }

  return 0;
}
