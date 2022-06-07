#include <stdio.h>

int main()
{

  int m, sum, i, aux, cont;
  char op;

  cont = 1;

  while (1)
  {
    scanf("%d", &m);

    if (m == 0)
      break;

    scanf("%d", &sum);

    for (i = 0; i < m - 1; i++)
    {
      scanf("%c", &op);
      scanf("%d", &aux);

      if (op == '-')
      {
        sum -= aux;
      }
      else
      {
        sum += aux;
      }
    }

    printf("Teste %d\n", cont);
    cont++;
    
    printf("%d\n", sum);
  }

  return 0;
}

// 3
// 123 +23-1
