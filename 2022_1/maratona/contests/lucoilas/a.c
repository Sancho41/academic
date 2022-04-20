#include <stdio.h>

void solve(int i)
{
  int n, r, j = i - 1;
  char p;

  scanf("%d", &r);

  while (j--)
  {
    scanf("%c", &p);
    scanf("%d", &n);
    r += p == '+' ? n : -n;
  }

  printf("%d\n", r);
}

int main()
{
  int n, cont = 1;

  scanf("%d", &n);
  while (n != 0)
  {
    printf("Teste %d\n", cont++);
    solve(n);
    scanf("%d", &n);
  }
}
