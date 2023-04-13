#include <stdio.h>
#include <stdlib.h>
#include "matrice1.h"
#include "matrice1.c"

int main(int argc, char *argv[argc]){

  int N = 4;
  double x[4] = {1,2,3,4};
  double A[16]={1,2,1,2,-2,-3,0,-5,4,8,6,7,1,-1,0,5};
  double y[4];
  double B[16]={-24,-5,4,-1,6,1,-1,0,1,0.6,0,0.2,6,1.2,-1,0.4};
  double C[16];

  printf("Vecteur x :\n");
  afficheVec(x,N);
  printf("\n");

  printf("Matrice A :\n");
  afficheMat(A,4);
  printf("\n");

  prodMatVec(A,x,y,N);
  printf("y = A * x :\n");
  afficheVec(y,N);
  printf("\n");

  prodMatMat(A,B,C,N);
  printf("C = A * B :\n");
  afficheMat(C,N);
  printf("\n");

  return 0;
}
