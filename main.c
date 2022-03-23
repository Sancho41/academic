#include <stdio.h>
#include <string.h>

int main()
{
  char *string1 = "0010010010010";
  char *string2 = "001";

  int count = 0, i, j;

  for (i = 0; string1[i] != '\0'; i++)
  {
    for (j = 0; string2[j] != '\0' && string1[i + j] == string2[j]; j++);

    if (j == strlen(string2)) {
      count++;
      i += j - 1;
    }
  }

  printf("%d\n", count);

  return 0;
}
