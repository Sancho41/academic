#include <stdio.h>

long long int produto(long long int x)
{
  long long int prod = 1;

  if (x <= 0)
    return 0;

  while (x > 0)
  {
    prod *= (x % 10);
    x /= 10;
  }
  return prod;
}

int main()
{
  long long int n, curr, p, check, ans = 1;

  scanf("%lld", &n);
  ans = produto(n);

  for (p = 1; p <= n; p *= 10)
  {
    curr = (n / p) * p;
    check = produto(curr - 1);
    ans = (ans > check) ? ans : check;
  }

  return 0;
}
