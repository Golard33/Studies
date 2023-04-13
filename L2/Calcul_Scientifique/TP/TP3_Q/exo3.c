#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrice3.h"
#include "matrice3.c"

int main(){

  double A[9]={4,2,0,4,4,2,2,2,3};
  double B[16]={1,2,1,2,-2,-3,0,-5,4,8,6,7,1,-1,0,5};
  double L[9];
  double U[9];
  double V[9];
  double L2[16];
  double U2[16];
  double V2[16];
  double y[3];
  double x[3];
  double b[3]={2,4,6};


  decompositionLU ( A , L , U , 3);
  printf("\nDécomposition LU de la matrice A :\n");
  afficheMat(U,3);
  printf("\n");

  printf("On a bien L . U = A :\n");
  prodMatMat(L, U, V, 3);
  afficheMat(V,3);
  printf("\n");
  


  decompositionLU ( B , L2 , U2 , 4);
  printf("Décomposition LU de la matrice B : \n");
  afficheMat(U2,4);
  printf("\n");

resolutionSystLin(A, b, x, 3);

printf("x : \n");
afficheVec(x,3);
printf("\n");

printf("b : \n");
afficheVec(b,3);
printf("\n");

printf("A * x = b :\n");
prodMatVec(A,x,y,3);
afficheVec(y,3);

}
