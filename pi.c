#include <omp.h>
#include <stdio.h>
static long num_steps = 1000000000; double step;
int threads = 10;


void main () { 
    int i, qtd_geral_threads; double pi=0.0, resultado_cada_thread[threads];

    step = 1.0/(double) num_steps;
    printf("Steps: %lf\n", step);   

    omp_set_num_threads(threads);
    
    #pragma omp parallel
    {

        int i, id,numero_threads;
        double x;
        id = omp_get_thread_num();
        numero_threads = omp_get_num_threads();
        printf("Numero threads: %d\n", numero_threads);
       

        resultado_cada_thread[id] = 0.0; // reset do valor de cada somatorio
        for (i=id;i< num_steps; i=i+numero_threads) {

            x = (i+0.5)*step;
            resultado_cada_thread[id] += 4.0/(1.0+x*x);
        }

    }

    for(i=0;i<threads;i++){
        pi += resultado_cada_thread[i] * step;
    }

    printf("%lf\n", pi);
}



















 // if (id == 0) { // limite do for de juncao dos resultados, uma thread somente usa
        //     qtd_geral_threads = numero_threads;
        // }