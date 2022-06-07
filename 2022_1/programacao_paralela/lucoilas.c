#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define sleep 0.1



void my_time(){
    double time = omp_get_wtime();
    while (omp_get_wtime() < (time + sleep));
}
int division(int a, int b){
    my_time();
    return !(a % b) ? 1 : 0; 
}

int main(int argc, char const *argv[])
{
    int nthr = atoi(argv[1]);
    int n;
    int *input;
    int num_of_prim=0;
    int sum_of_prim=0;
    int *prims;
    double t1, t2;
    scanf("%d", &n);
    prims = (int*)malloc(sizeof(int)*n);
    input = (int*)malloc(sizeof(int)*n);

    omp_set_num_threads(nthr);
    for(int i = 0; i<n; i++){
        scanf("%d", &input[i]);
    }
    t1 = omp_get_wtime();

        #pragma omp parallel for
            for(int i = 0; i<n; i++){
                int isPrime = 1;
                if(input[i] == 1 || input[i] == 0){
                    continue;
                }
                for(int j = 2; j <= input[i]/2; j++){
                    if(division(input[i], j)){
                        isPrime = 0;
                        break;
                    }
                }
                
                #pragma omp critical 
                {
                    if(isPrime){
                        sum_of_prim += input[i];
                        prims[num_of_prim] = input[i];
                        num_of_prim++;
                    }
                }
            }

    t2 = omp_get_wtime();

    printf("time %f with %d\n", t2 - t1, nthr);
    
    printf("num_of_prim %d\n", num_of_prim);
    printf("sum_of_prim %d\n", sum_of_prim);
    printf("prims\n");
    for(int i = 0; i<num_of_prim; i++){
        printf("%d ", prims[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");

    return 0;
}



/*

time 7.000043 with 1
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 3.500066 with 2
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 2.800125 with 3
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 2.100133 with 4
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 1.406988 with 5
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 1.400202 with 6
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 1.400220 with 7
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 1.400369 with 8
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 1.400446 with 9
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 


time 0.700342 with 10
num_of_prim 10
sum_of_prim 170
prims
17 17 17 17 17 17 17 17 17 17 

*/
