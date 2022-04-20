#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define CONSUME_SLEEP 0.8
#define PRODUCE_SLEEP 0.2
#define VECTOR_SIZE 10
#define THREADS 5
#define N 1

#define FORMAT_PRODUCER "\033[32m[i=%d, t=%d]: %d\n\033[0m"
#define FORMAT_CONSUMER "\033[34m[i=%d, t=%d]: %d\n\033[0m"

void produce(int *vector, int quantity);
void consume(int *vector);
void sleep(double time);

int TOP = 0;

int main()
{
  int i;
  int vector[VECTOR_SIZE];

#pragma omp parallel num_threads(THREADS)
  {

#pragma omp master
    while (TRUE)
      produce(vector, N);

    while (TRUE)
      consume(vector);
  }

  return 0;
}

void produce(int *vector, int quantity)
{
  int i, random;

  sleep(PRODUCE_SLEEP);

#pragma omp critical
  for (i = 0; i < quantity; i++)
    if (TOP < VECTOR_SIZE)
    {
      random = (rand() % 100) + 1;
      vector[TOP] = random;

      printf(FORMAT_PRODUCER, TOP, omp_get_thread_num(), random);

      TOP++;
    }
}

void consume(int *vector)
{
  int consumed;

  sleep(CONSUME_SLEEP);

#pragma omp critical
  if (TOP > 0)
  {
    TOP--;

    consumed = vector[TOP];
    printf(FORMAT_CONSUMER, TOP, omp_get_thread_num(), consumed);
  }
}

void sleep(double time)
{
  double initial = omp_get_wtime();
  while (omp_get_wtime() < (initial + time))
    continue;
}
