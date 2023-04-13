#include <stdio.h>
#include <math.h>
#include "matrice2.h"
#include "matrice2.c"

int main() {
  int n = 3;
  double x[3];
  double y[3];
  double c[3];
  double d[3];


  double z[3] = {2,2,4};

  double b[3]={2,4,6};

  double L[9]={1,0,0,
               1,1,0,
               0.5,0.5,1};

  double U[9]={4,2,0,
                0,2,2,
                0,0,2};



  printf("\nDescente matrice L et vecteur b\n");
  descente(L, b, y, n);
  afficheVec (y,  n);
  printf("\n");

  prodMatVec(L,y,c,n);
  printf("b=\n");
  afficheVec(b,n);
  printf("\n");

  printf("On a bien b = L . y :\n");
  afficheVec(c,n);
  printf("\n");


  printf("Remontee matrice U et vecteur y\n");
  remontee(U, z, x, n);
  afficheVec (x,  n);
  printf("\n");

  prodMatVec(U,x,d,n);
  printf("y =\n");
  afficheVec(y,n);
  printf("\n");

  printf("On a bien y = U . x :\n");
  afficheVec(d,n);
  printf("\n");



return 0;
}
