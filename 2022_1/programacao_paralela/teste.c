#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SLEEP 0.1

void do_parallel(int threads);
void do_stuf();
int big_ass_method(int a, int b);
int prime(int x);

int main(int argc, char **argv)
{
  int threads = argc >= 2 ? atoi(argv[1]) : 4;
  do_parallel(threads);
  return 0;
}

void do_parallel(int threads)
{
  double time;

  omp_set_num_threads(threads);

  time = omp_get_wtime();

  printf("== Threads requested: %d\n", threads);

  do_stuf();

  printf("Time: %f\n\n", omp_get_wtime() - time);
}

void do_stuf()
{
  int n, i;
  int *a;

  scanf("%d", &n);

  a = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int cont_prime = 0, sum_prime = 0;

#pragma omp parallel for reduction(+:cont_prime, sum_prime)
  for (i = 0; i < n; i++)
    if (prime(a[i]))
    {
      cont_prime++;
      sum_prime += a[i];
    }
    else
      a[i] = 0;

  printf("Qtd primo: %d\n", cont_prime);
  printf("Sum primo: %d\n", sum_prime);
  printf("Numeros primos: ");
  for (i = 0; i < n; i++)
    if (a[i] != 0)
      printf("%d ", a[i]);
  printf("\n");
}

int big_ass_method(int a, int b)
{
  double time = omp_get_wtime();
  while (omp_get_wtime() < (time + SLEEP));

  return a % b == 0;
}

int prime(int x)
{
  if (x == 1 || x == 2)
    return 1;
  int i, cont = 0;

  for (i = 2; i <= (x / 2) && cont < 1; i++)
    cont += big_ass_method(x, i);

  return cont == 0;
}
