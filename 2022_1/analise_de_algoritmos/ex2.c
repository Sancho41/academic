#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Saída
// Iterativo de 1: 1 [0.000000]
// Recursivo de 1: 1 [0.000000]
// Matricial de 1: 1 [0.000000]

// Iterativo de 5: 5 [0.000000]
// Recursivo de 5: 5 [0.000000]
// Matricial de 5: 5 [0.000000]

// Iterativo de 10: 55 [0.000000]
// Recursivo de 10: 55 [0.000000]
// Matricial de 10: 55 [0.000000]

// Iterativo de 15: 610 [0.000000]
// Recursivo de 15: 610 [0.000000]
// Matricial de 15: 610 [0.000000]

// Iterativo de 20: 6765 [0.000000]
// Recursivo de 20: 6765 [0.000000]
// Matricial de 20: 6765 [0.000000]

// Iterativo de 25: 75025 [0.000000]
// Recursivo de 25: 75025 [0.001000]
// Matricial de 25: 75025 [0.000000]

// Iterativo de 30: 832040 [0.000000]
// Recursivo de 30: 832040 [0.002000]
// Matricial de 30: 832040 [0.000000]

// Iterativo de 35: 9227465 [0.000000]
// Recursivo de 35: 9227465 [0.026000]
// Matricial de 35: 9227465 [0.000000]

// Iterativo de 40: 102334155 [0.000000]
// Recursivo de 40: 102334155 [0.286000]
// Matricial de 40: 102334155 [0.000000]

// Iterativo de 45: 1134903170 [0.000000]
// Recursivo de 45: 1134903170 [3.167000]
// Matricial de 45: 1134903170 [0.000000]

// Iterativo de 50: 12586269025 [0.000000]
// Recursivo de 50: 12586269025 [35.089000]
// Matricial de 50: 12586269025 [0.000000]

long long int fibonacci_iterativo(int n);
long long int fibonacci_recursivo(int n);
long long int fibonacci_matricial(int n);

int main(int argc, char **argv)
{

  int n = atoi(argv[1]);
  double time;

  time = omp_get_wtime();

  printf("Iterativo de %d: %lld ", n, fibonacci_iterativo(n));
  printf("[%lf]\n", omp_get_wtime() - time);

  time = omp_get_wtime();

  printf("Recursivo de %d: %lld ", n, fibonacci_recursivo(n));
  printf("[%lf]\n", omp_get_wtime() - time);

  time = omp_get_wtime();

  printf("Matricial de %d: %lld ", n, fibonacci_matricial(n));
  printf("[%lf]\n\n", omp_get_wtime() - time);

  return 0;
}

long long int fibonacci_iterativo(int n)
{
  long long int f1 = 0, f2 = 1, f3;
  int i;

  if (n == 1 || n == 2)
    return 1;

  for (i = 2; i <= n; i++)
  {
    f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }

  return f2;
}

long long int fibonacci_recursivo(int n)
{

  if (n == 1 || n == 2)
    return 1;

  return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

long long int fibonacci_matricial(int n)
{
  int long long *matrix = (long long int *)malloc(sizeof(long long int) * n * 3);
  int i, x, y;

  matrix[0] = 0;
  matrix[1] = 1;
  matrix[2] = 1;

  for (i = 1; i < n - 1; i++) {
    matrix[i * 3] = matrix[((i - 1) * 3) + 1];
    matrix[(i * 3) + 1] = matrix[((i - 1) * 3) + 2];
    matrix[(i * 3) + 2] = matrix[i * 3] + matrix[(i * 3) + 1];
  }

  return matrix[n * 3 - 1];
}
