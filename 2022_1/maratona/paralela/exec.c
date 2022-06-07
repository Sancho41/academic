#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

long int fibonacci(long int n);
long int last_alive(long int qtd);
long int hanoi(long int disks);
long int even_sum(long int n);
long int fact_sum(long int n);
long int prime_sum(long int n);
int primo(int x);

void master();
void slave(int id);

int main()
{
    MPI_Init(NULL, NULL);
    int id_processo;

    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);

    if (id_processo == 0)
        master();
    else
        slave(id_processo);

    MPI_Finalize();

    return 0;
}

void master()
{
    int i, n;
    long int result;
    MPI_Status status;

    scanf("%d", &n);

    for (i = 1; i <= 6; i++)
        MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

    for (i = 1; i <= 6; i++)
    {
        MPI_Recv(&result, 1, MPI_LONG_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);

        switch (status.MPI_SOURCE)
        {

        case 1:
            printf("fibonacci(%d)", n);
            break;
        case 2:
            printf("last_alive(%d)", n);
            break;
        case 3:
            printf("hanoi(%d)", n);
            break;
        case 4:
            printf("even_sum(%d)", n);
            break;
        case 5:
            printf("fact_sum(%d)", n);
            break;
        case 6:
            printf("prime_sum(%d)", n);
            break;
        }

        printf("Result from %d: %ld\n", result);
    }
}

void slave(int id)
{
    long int result;
    int n;
    MPI_Status status;

    MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

    switch (id)
    {
    case 1:
        result = fibonacci(n);
        break;
    case 2:
        result = last_alive(n);
        break;
    case 3:
        result = hanoi(n);
        break;
    case 4:
        result = even_sum(n);
        break;
    case 5:
        result = fact_sum(n);
        break;
    case 6:
        result = prime_sum(n);
        break;
    }

    MPI_Send(&result, 1, MPI_LONG_INT, 0, 0, MPI_COMM_WORLD);
}

long int fibonacci(long int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long int prime_sum(long int n)
{
    int i;
    long long int r = 0;
    for (i = 1; i <= n; i++)
        if (primo(i))
            r = r + i;

    return r;
}

long int fact_sum(long int n)
{
    long int fat = 1, r = 0, i;

    for (i = 2; i <= n; i++)
        fat = fat * i;

    for (i = 1; i <= fat; i++)
        r = r + i;

    return r;
}

long int even_sum(long int n)
{
    long int sum = 0, i;
    for (i = 1; i <= n; i++)
        sum += i % 2 == 0 ? 0 : i;
    return sum;
}

long int hanoi(long int disks)
{
    long int moves = 0;
    if (disks > 0)
    {
        moves = hanoi(disks - 1);
        moves++;
        moves += hanoi(disks - 1);
    }

    return moves;
}

long int last_alive(long int qtd)
{
    long int *people = (long int *)calloc(sizeof(long int), qtd);
    long int dead = 0;
    long int i = 0, alive;

    while (dead != qtd - 1)
    {
        people[i] = 1;
        dead++;
        alive = 0;

        while (alive != 2)
        {
            i = (i + 1) % qtd;
            alive += people[i] == 0;
        }
    }

    return i + 1;
}

int primo(int x)
{

    if (x == 0 || x == 1)
        return 0;

    int div;

    for (div = 2; div < x; div++)
        if (x % div == 0)
            return 0;

    return 1;
}
