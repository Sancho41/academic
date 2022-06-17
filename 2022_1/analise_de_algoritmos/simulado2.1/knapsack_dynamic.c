#include <stdio.h>
#include <stdlib.h>

int knapsack(int *profits, int *weight, int size, int capacity, int *included_arr);

int main()
{
  int profits[] = {60, 100, 120};
  int weights[] = {10, 20, 30};
  int *included_arr;
  int i;
  int capacity = 50;
  int result;

  int size = sizeof(profits) / sizeof(profits[0]);
  included_arr = (int *)calloc(sizeof(int), size);

  result = knapsack(profits, weights, size, 50, included_arr);

  printf("Result %d\n", result);

  for (i = 0; i < size; i++)
    if (!included_arr[i])
      printf("(%d %d),", weights[i], profits[i]);
  printf("\n");

  return 0;
}

int knapsack(int *profits, int *weight, int size, int capacity, int *included_arr)
{
  int line_size = size + 1, col_size = capacity + 1;
  int i, j;
  int table[line_size][col_size];
  int included, excluded;

  for (i = 0; i < line_size; i++)
    for (j = 0; j < col_size; j++)
      table[i][j] = 0;

  for (i = 0; i < line_size; i++)
    for (j = 0; j < col_size; j++)
      if (i == 0 || j == 0)
        table[i][j] = 0;
      else
      {
        if (weight[i - 1] > capacity)
          table[i][j] = table[i - 1][j];
        else
        {
          excluded = table[i - 1][j];
          included = table[i - 1][j - weight[i - 1]] + profits[i - 1];

          table[i][j] = included > excluded ? included : excluded;
        }
      }

  int res = table[size][capacity];
  int J = size;

  for (i = size; i > 0 && res > 0; i--)
  {
    if (table[i - 1][J])
      continue;

    included_arr[i - 1] = 1;

    res = res - profits[i - 1];
    J = j - weight[i - 1];
  }

  return table[size][capacity];
}
