#include <stdio.h>
#include <math.h>
#include "interpolation.h"


double base_lagrange (double x, int i, double *X, int n) 
{

float lx = 1.0; 
       for (int j = 0; j<n;j++){
        if(j!=i){
            lx*= (x-X[j]/(X[i]-X[j]));
        }
       }

 return lx;
}

double eval_p (double x, double *X, double *Y, int n) 
{

    float p = 0.0;
    for (int i = 0; i<n ;i++){
        p+= Y[i]* base_lagrange (x, i , X, n);
    }
    return p ; 
}

void differences_divisees (double *N, double *X, double *Y, int n)
{

    for (int i = 0; i <= n ; i++)
    {
        N[i] =Y[i];
    }

    for (int i = 1; i <=n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            
            N[j] = ((N[j]-N[j-1])/(X[j]-X[j-i]));
        }
    }
}

double eval_p_dd (double x, double *N, double *X, double *Y, int n)
{
    double p ; 
    double q ; 

    p = N[0];
    q = 1;
    for ( int i = 1; i<= n ; i++){
        q = q*(x-X[i-1]);
        p = (p + q * N[i]);
    }
    return p ; 
}