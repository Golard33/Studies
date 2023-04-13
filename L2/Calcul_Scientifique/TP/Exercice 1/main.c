#include <stdio.h>
#include <math.h>
#include "matrice.h"

int main(int argc, char *argv[argc])
{
    //printf("------------------------ \r\n");
    
    int n = 4;
    
    // Vecteurs
    double x[4]={1,2,3,4};
    double y[4];
    
    // Matrices
    double A[16]={1, 2, 1, 2,
                 -2, -3, 0, -5,
                  4, 8, 6, 7,
                  1, -1, 0, 5};
    
    double B[16]={ -24, -5, 4, -1,
                    6, 1, -1, 0,
                    1, 0.6, 0, 0.2,
                    6, 1.2, -1, 0.4};
        
    double C[16];

    // Fonctions
    //afficheVec(x,n);
    //afficheMat(A,n);
    
    prodMatVec(A,x,y,n);
    afficheVec(y,n);
    
    printf("Produit Mat-Mat \n");
    prodMatMat(A,B,C,n);
    afficheMat(C,n);
    
    return 0;
}
