#include <stdio.h>
#include <stdlib.h>
#include "matrice1.h"

void afficheVec(double *x, int n){
  int i;
  for (i = 0; i < n; i++){
    printf("%lg\n",x[i] );
  }
}

void afficheMat(double *A, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%lg\t",A[i*n+j]);
    }
    printf("\n");
  }
}

void prodMatVec(double *A, double *x, double *y, int n){
  for(int i=0;i<n;i++){
y[i]=0;
    for (int j=0;j<n;j++){
      y[i] = y[i] +(A[i*n+j])*(x[j]);
    }
  }
}


void prodMatMat(double *A, double *B, double *C, int n){
  for (int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i*n+j]=0;
      for (int k=0;k<n;k++){
        C[i*n+j]=C[i*n+j]+(A[i*n+k]*B[k*n+j]);
      }
    }
  }
}
