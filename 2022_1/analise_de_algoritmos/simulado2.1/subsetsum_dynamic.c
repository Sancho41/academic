#include <stdio.h>

int subset(int arr[], int size, int sum);

int main()
{
  int arr[] = {3, 4, 5, 2};
  int sum = 10, has_subset;

  int size = sizeof(arr) / sizeof(arr[0]);
  has_subset = subset(arr, size, sum);

  printf("Has subset %d\n", has_subset);

  return 0;
}

int subset(int arr[], int size, int sum)
{
  int lines = size + 1, cols = sum + 1;
  int table[lines][cols];
  int i, j;

  for (i = 0; i < lines; i++)
    table[i][0] = 1;

  for (i = 1; i < cols; i++)
    table[0][i] = 0;

  for (i = 1; i < lines; i++)
    for (j = 1; j < cols; j++)
      if (j < arr[i - 1])
        table[i][j] = table[i - 1][j];
      else
        table[i][j] = table[i - 1][j] || table[i - 1][j - arr[i - 1]];

  return table[size][sum];
}
