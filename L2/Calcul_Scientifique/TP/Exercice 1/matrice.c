#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"


void afficheVec(double *x, int n)
{
    printf("x = \n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("| %g |\n", x[i]);
        //printf("| %24.16lf |\n", x[i]);
    }
}

void afficheMat(double *A, int n)
{
    printf("A = \n");
    for(int i = 0; i < n ; i++)
    {
        printf("| ");
        for(int j = 0 ; j < n ; j++)
        {
            printf("%g\t", A[i*n+j]);
            //printf("%24.16lf\t", A[i*n+j]);
        }
        printf(" |\n");
    }
}

void prodMatVec(double *A, double *x, double *y, int n)
{
    double sum;
    
    for (int i = 0 ; i < n ; i++)
    {
        sum = 0;
        
        for(int j = 0 ; j < n ; j++)
        {
            sum += A[i*n+j] * x[j];
        }
        
        y[i] = sum;
    }
}

void prodMatMat(double *A, double *B, double *C, int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i*n+j] = 0;
            for (int k = 0 ; k < n ; k++)
            {
                C[i*n+j] += A[i*n+k] * B[k*n+j];
            }
        }
    }
}
