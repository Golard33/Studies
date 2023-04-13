#include <stdio.h>
#include <math.h>
#include "matrice.h"
#define n 3

int main(int argc, char* argv[argc])
{
    double x[n];
    double y[n];
    double a[n];
    double w[n] =  {2,2,4};
    double C[n];
    double L[n*n] = {1,0,0,1,1,0,0.5,0.5,1};
    double b[n] = {2,4,6};
    double U[n*n] = {4,2,0,0,2,2,0,0,2};



    printf(" algo descente\n");
    descente ( L, b, y, n);
    afficheVec(y, n);

    printf(" produit matrice avec L\n");
    prodMatVec(L,y,C,n); 

    printf("b=\n");
    afficheVec(b,n);

    printf("On a bien b = L . y :\n");
    afficheVec(C,n);
    printf("-------------------------------\n");



    printf(" algo remontée\n");
    remontee( U, w, x, n);
    afficheVec(x, n);

    printf(" produit matrice avec L\n");
    prodMatVec(U,x,a,n); 

    printf("b=\n");
    afficheVec(y,n);

    printf("On a bien y = U . x :\n");
    afficheVec(a,n);



    
}