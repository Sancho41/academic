#include <stdio.h>

int main()
{
  int m, res, n, i, cont;
  char op;

  cont = 1;

  while (1)
  {
    scanf("%d", &m);

    if (m == 0)
      break;

    scanf("%d", &res);

    for (i = 0; i < m - 1; i++)
    {
      scanf("%c%d", &op, &n);

      if (op == '+')
        res += n;
      else
        res -= n;
    }

    printf("Teste %d\n", cont);
    printf("%d\n", res);

    cont++;
  }

  return 0;
}
