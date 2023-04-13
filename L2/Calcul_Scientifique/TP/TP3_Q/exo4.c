#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "matrice4.h"
#include "matrice4.c"

int main() {
  int n;
  double *A;
  double *B;
  printf("\nValeur de n :");
  scanf("%d", &n);

  A=malloc(n*n*sizeof(double));
  B=malloc(n*n*sizeof(double));

  A[0*n+0] = 3;
  A[0*n+1] = -1;
  A[(n-1)*n+n-2] = -1;
  A[(n-1)*n+n-1] = 3;
  for (int i = 1; i < n-1; i++){
      A[i*n+(i-1)]=-1;
      A[i*n+(i)]=3;
      A[i*n+(i+1)]=-1;
  }

  printf("\nMat A :\n");
  afficheMat(A,n);

  inverse(A,B,n);
  printf("Inverse de la matrice A:\n");
  afficheMat(B,n);

  inverse_opt(A,B,n);
  printf("\nInverse optimisée de la matrice A:\n\n");
  afficheMat(B,n);

  clock_t tstart , tend ;
  tstart = clock () ;
  inverse (A ,B , n ) ;
  tend = clock () ;
  double time_comp = (( double ) ( tend - tstart ) ) / CLOCKS_PER_SEC *1000; // en millisecondes
  printf("\nComputational time : % lf ms \n",time_comp);


  tstart = clock () ;
  inverse_opt(A ,B , n ) ;
  tend = clock () ;
  time_comp = (( double ) ( tend - tstart ) ) / CLOCKS_PER_SEC *1000; // en millisecondes
  printf("\nComputational time : % lf ms \n",time_comp);


//Question 5: on observe l'obtention d'un résultat plus rapidement avec la seconde méthode

}
