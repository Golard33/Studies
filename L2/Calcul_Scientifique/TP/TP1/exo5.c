#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "interpolation.h"
#define n_max 1000

double formule(float X[], float Y[], int n, double val)
{
    double P,l1,l2;
    for(int i = 0; i<n-1;i++)
    {
        if((val - X[i] < 1)&& (X[i+1] - val < 1))
        {
            l1 = ((val-X[i]) / (X[i+1] - X[i]));
            l2 = 
        }
    }
}