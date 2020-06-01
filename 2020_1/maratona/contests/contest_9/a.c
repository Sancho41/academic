#include <stdio.h>

int main()
{
  int m, n, qtd, i, j, cand;
  qtd = 0;

  scanf("%d%d", &m, &n);

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &cand);
      qtd += cand;
    }
  }

  printf("%d\n", qtd);

  return 0;
}