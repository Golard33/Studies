#include <stdio.h>
#include <math.h>
#include "matrice.h"
#define n 4

int main(int argc, char* argv[argc])
{
    double x[n] = {1,2,3,4};
    double y[n];
    double A[n*n] = {1,2,1,2,-2,-3,0,-5,4,8,6,7,1,-1,0,5};
    double B[n*n] = {-24,-5,4,-1,6,1,-1,0,1,0.6,0,0.2,6,1.2,-1,0.4};
    double C[n*n];
    double L[9] = {1,0,0,1,1,0,0.5,0.5,1};
    double b[3] = {2,4,6};


    //afficheVec(x, n); 
    //afficheMat(A, n);

    prodMatVec(A,x,y,n);
    afficheVec(y,n);

    printf("produit de matrice \n");
    prodMatMat(A, B, C, n);
    afficheMat(C,n);

    printf(" algo descente\n");
    descente ( L, b, y, n);

    printf(" produit matrice avec L");
    prodMatVec(L,y,c,n); 

    printf("b=\n");
    afficheVec(b,n);

  printf("On a bien b = L . y :\n");
  afficheVec(c,n);

    
}