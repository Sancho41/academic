#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double calculate_integration(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0;
  double x = a;
  int i;
  #pragma omp parallel for reduction(+:sum)
  for (i = 0; i < n; i++) {
    sum += 4.0 / (1.0 + x * x);
    x += h;
  }
  return sum * h / 3.0;
}


int main () {
  
  double a = calculate_integration(-1.0, 1.0, 1000000);
  printf("%.16f\n", a);

  return 0;  
}
