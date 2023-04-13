#include <stdio.h>
#include <stdlib.h>
#include "matrice2.h"

void afficheVec(double *x, int n){
  int i;
  for (i = 0; i < n; i++){
    printf("%lg\n",x[i] );
  }
}

void prodMatVec(double *A, double *x, double *y, int n){
  for(int i=0;i<n;i++){
y[i]=0;
    y[i]=0;
    for (int j=0;j<n;j++){
      y[i] = y[i] +(A[i*n+j])*(x[j]);
    }
  }
}


void descente(double *L, double *b, double *y, int n)
{
  int i,j;
  for(i=0; i<n; i++)
    {
      y[i]=b[i];
      for(j=0; j<=i-1; j++)
        {
          y[i]-=L[i*n+j]*y[j];
        }
    }

}

void remontee(double *U, double *y, double *x, int n)
{
 for (int i=n-1;i>=0;i--){
   x[i]=y[i];
   for(int j=i+1; j<=n-1; j++){
       x[i]= x[i] - U[i*n+j]*x[j];
     }
     x[i]=x[i]/U[i*n+i];
  }
}
