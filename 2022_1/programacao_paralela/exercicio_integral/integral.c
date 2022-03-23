#include <stdio.h>
#include <omp.h>

static long long num_steps = 100000000000;
double step;

int main () {
  long long int i;
  long int time = omp_get_wtime();
  double x, pi, sum = 0.0;

  step = 1.0 / (double) num_steps;

  for (i = 0; i < num_steps; i++) {
    x = (i + 0.5) * step;
    sum = sum + 4.0 / (1.0 + x * x);
  }

  pi = step * sum;

  printf("Pi: %lf Time: %lf\n", pi, omp_get_wtime() - time);
  return 0;
}
