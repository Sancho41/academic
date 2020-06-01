#include <stdio.h>
#include <math.h>

int main ()
{
  int qtd, quad;
  double current;

  scanf("%d", &qtd);

  scanf("%lf", &current);
  qtd--;
  current = sqrt(current);
  quad = (int)current == current;

  while (qtd--)
  {
    scanf("%lf", &current);
    current = sqrt(current);
    if ((current == (int)current) != quad)
    {
      quad = !quad;
    }
    else
    {
      printf("TROQUE DE MINISTRO\n");
      return 0;
    }
  }

  printf("O MINISTRO FICA\n");
  return 0;
}
