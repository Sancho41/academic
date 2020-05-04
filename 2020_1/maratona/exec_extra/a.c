#include <stdio.h>

int main()
{
  int i = 0;
  int j = 1;
  int cont = 1;

  while (scanf("%d", &i) == 1)
  {
    j = 1;
    cont = 1;

    while (j)
    {
      j = ((j * 10) + 1) % i;
      cont++;
    }
    printf("%d\n", cont);
  }

  return 0;
}
