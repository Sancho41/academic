#include <stdio.h>

void solve()
{
  char s[50];
  char c;
  int i;

  scanf("%s", s);
  scanf("%*c%c", &c);

  for (i = 0; s[i] != '\0'; i++)
  {
    if (s[i] == c && i % 2 == 0)
    {
      printf("YES\n");
      return;
    }
  }
  
  printf("NO\n");
}

int main()
{
  int n;
  scanf("%d", &n);

  while (n--)
    solve();

  return 0;
}
