#include <stdio.h>

int subset(int arr[], int size, int index, int sum);

int main()
{
  int arr[] = {3, 4, 5, 2, 9};
  int sum = 9, has_subset;

  has_subset = subset(arr, 4, 0, sum);

  printf("Has subset %d\n", has_subset);

  return 0;
}

int subset(int arr[], int size, int index, int sum)
{
  if (sum == 0)
    return 1;

  if (index == size)
    return 0;

  if (arr[index] > sum)
    return subset(arr, size, index + 1, sum);

  if (subset(arr, size, index + 1, sum))
    return 1;

  return subset(arr, size, index + 1, sum - arr[index]);
}