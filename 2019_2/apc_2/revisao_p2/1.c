#include <stdio.h>
#include <stdlib.h>

int quadrante(int x, int y);

int main() {

    int tam, i;
    int * x, * y;

    printf("Digite a quantidade de coordenadas que deseja verificar: ");
    scanf("%d", &tam);

    x = (int *)malloc(sizeof(int) * tam);
    y = (int *)malloc(sizeof(int) * tam);

    printf("Digite as cordenadas, x e y por linha:\n");
    for (i = 0; i < tam; i++)
        scanf("%d %d", &x[i], &y[i]);
    
    for (i = 0; i < tam; i++)
        printf("\nA coordenada (%d, %d) esta no quadrante %d", x[i], y[i], quadrante(x[i], y[i]));
    
    printf("\n");

    return 0;
}

int quadrante(int x, int y){

    int x_pos, y_pos;
    x_pos = x > 0;
    y_pos = y > 0;

    if (x_pos){
        if (y_pos)
            return 1;
        return 4;
    } 
    if (y_pos)
        return 2;
    return 3;
}