#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

void afficheVec(double *x, int n)
{
    int i;
    for (i= 0; i< n; i++)
    {
        printf (" | %f | \n", x[i]);
    }
}

void afficheMat(double *A, int n)
{
    int i, j;
    for (i= 0; i< n; i++)
    {
        printf("|");
        for (j = 0; j< n; j++)
        {
            printf(" %f\t", A[i*n+j]);
        }
        printf("|\n");
    }
}

void prodMatVec(double *A, double *x, double *y, int n)
{
    int i, j;
    double somme;
    for (i= 0; i< n; i++)
    {
        somme = 0;
        for (j = 0; j< n; j++)
        {
            somme += A[i*n+j] * x[j];
        }
        y[i] = somme;
    }
}

void prodMatMat(double *A, double *B, double *C, int n)
{
    int i, j,k;
    for (i= 0; i< n; i++)
    {
        for (j = 0; j< n; j++)
        {
            C[i*n+j] = 0;
            for(k = 0; k< n; k++)
            {
                C[i*n+j] += (A[i*n+k] * B[k*n+j]);
            }
        }
    }
}

void descente (double *L, double *b, double *y, int n)
{
    int i,j;
    for (i=0; i<n ; i++)
    {
        y[i] = b[i];
        for (j=0 ;j<=i-1 ; j++)
        {
            y[i]-= L[i*n+j] *y[j];
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

void decompositionLU(double*A, double *L, double *U, int n) {
for (int i = 0; i < n*n; i++) {
  U[i]=A[i];
}
  for (int r = 0; r < n; r++) {
    L[r*n+r] = 1;
    for (int i = 0; i < r; i++) {
      L[i*n+r] = 0;

    }
    for (int i = r+1; i < n; i++) {
      L[i*n+r]=U[i*n+r]/U[r*n +r];
      for (int j = r+1; j < n; j++) {
        U[i*n+j]=U[i*n+j]-L[i*n+r]*U[r*n+j];
      }
      U[i*n+r]=0;
    }
  }
}


void resolutionSystLin(double *A, double *b, double *x, int n) {
double *L;
double *U;
double *y;
L=calloc(n*n,sizeof(*L));
U=calloc(n*n,sizeof(*U));
y=calloc(n*n,sizeof(*y));

decompositionLU(A, L, U, n);
descente(L, b, y, n);
remontee(U, y, x, n);
free(L);
free(U);
free(y);
}

void inverse ( double *A , double *B , int n ){
  double *e=calloc(n*n, sizeof(*e));
  double *v=calloc(n*n, sizeof(*v));
  for(int j=0;j<n;j++){
    //ecriture de e
    for(int i=0;i<n;i++){
      if(i==j){
        e[i]=1;
      }
      else{
      e[i]=0;
      }
    }
    //resolution de Av=e
    resolutionSystLin(A,e,v,n);
    //réecriture de v
    for(int i=0;i<n;i++){
      B[i*n+j]=v[i];
    }
  }
}

void inverse_opt ( double *A, double *B, int n){

  double *L=calloc(n*n, sizeof(*L));
  double *U=calloc(n*n, sizeof(*U));
  double *e=calloc(n*n, sizeof(*e));
  double *v=calloc(n*n, sizeof(*v));
  double *y=calloc(n*n, sizeof(*y));

  decompositionLU(A, L, U, n);

  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      if(i==j){
        e[i]=1;
      }
      else{
      e[i]=0;
      }
    }
    descente(L, e, y, n);
    remontee(U, y, v, n);
    for(int i=0;i<n;i++){
      B[i*n+j]=v[i];
    }
  }
}


