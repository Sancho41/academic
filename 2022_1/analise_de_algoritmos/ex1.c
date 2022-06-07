#include <stdio.h>

int main () {
  int t, a, b;
  scanf("%d %d %d", &t, &a, &b);

  printf("%d",((2 * t) + 3 + t) + (a * ((2 * t) + 2) + t) + (t * b));
}
