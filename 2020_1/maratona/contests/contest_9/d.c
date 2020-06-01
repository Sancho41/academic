#include <stdio.h>

int main ()
{
  int a, b, c, d, qtd;
  scanf("%d", &qtd);

  while(qtd--)
  {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", (a * b) + (c * d));
  }

  return 0;
}