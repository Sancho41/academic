#include <stdio.h>

int main()
{

  int i, qtd, div_even, sum_even, sum_odd, last_odd, j, diff;
  scanf("%d", &qtd);

  while (qtd--)
  {
    scanf("%d", &i);

    sum_even = ((2 + i) * (i / 2)) / 2;
    sum_odd = ((1 + i - 1) * (i / 2)) / 2;

    diff = sum_even - sum_odd;

    last_odd = i - 1 + diff;

    if (last_odd % 2 == 0)
      printf("NO\n");
    else
    {
      printf("YES\n");
      for (j = 1; j <= (i / 2); j++)
        printf("%d ", j * 2);

      for (j = 1; j < (i / 2); j++)
        printf("%d ", j * 2 - 1);

      printf("%d\n", last_odd);
    }
  }

  return 0;
}
