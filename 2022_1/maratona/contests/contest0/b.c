#include <stdio.h>

int main(int argc, char const *argv[])
{
  float x,y;

  scanf("%f %f", &x, &y);

  if(x == 0.0 && y == 0.0){
    printf("Origem");
  }else if(x > 0.0 && y > 0.0){
    printf("Q1");
  }else if(x < 0.0 && y > 0.0){
    printf("Q2");
  }else if(x < 0.0 && y < 0.0){
    printf("Q3");
  }else if(x > 0.0 && y < 0.0){
    printf("Q4");
  }else if(x == 0.0 && y != 0.0){
    printf("Eixo Y");
  }else if(x != 0.0 && y == 0.0){
    printf("Eixo X");
  }

  printf("\n");
  return 0;
}
