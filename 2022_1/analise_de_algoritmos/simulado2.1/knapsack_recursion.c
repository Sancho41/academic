#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int knapsack(int weights[], int profits[], int index, int space, int *result, int result_size);
void copy_arr(int *arr1, int *arr2, int size);

int main()
{
  int profits[] = {60, 100, 120};
  int weights[] = {10, 20, 30};
  int result[3] = {};
  int capacity = 50;
  int result_value, last_index, i;

  last_index = (sizeof(weights) / sizeof(weights[0])) - 1;

  result_value = knapsack(weights, profits, last_index, capacity, result, last_index + 1);

  printf("Result %d\n", result_value);

  for (i = 0; i <= last_index; i++)
    if (result[i])
      printf("(%d %d),", weights[i], profits[i]);
  printf("\n");

  return 0;
}

int knapsack(int weights[], int profits[], int index, int capacity, int *result, int result_size)
{
  int included, excluded;
  int *included_result = (int *)malloc(sizeof(int) * result_size);
  copy_arr(included_result, result, result_size);

  if (capacity == 0 || index == 0)
    return 0;

  if (weights[index] > capacity)
    return knapsack(weights, profits, index - 1, capacity, result, result_size);
  else
  {
    included = knapsack(weights, profits, index - 1, capacity - weights[index], included_result, result_size) + profits[index];
    excluded = knapsack(weights, profits, index - 1, capacity, result, result_size);

    if (included > excluded)
    {
      copy_arr(included_result, result, result_size);
      result[index] = 1;
      return included;
    }

    result[index] = 0;
    return excluded;
  }
}

void copy_arr(int *arr1, int *arr2, int size)
{
  int i;
  for (i = 0; i < size; i++)
    arr1[i] = arr2[i];
}
