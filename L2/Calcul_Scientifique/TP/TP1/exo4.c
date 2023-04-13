#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "interpolation.h"

int main (int argc, char *argv[])
{
  double x = 2018;
  float xk1;
  float k ;

  FILE* fichier = NULL;
  fichier = fopen("exo4.dat", "r+");

  if (fichier != NULL){
      int i;
      int n;
      rewind (fichier);
      fscanf(fichier, "%d", &n);
      printf( " n : %d \n", n);
      double *X;
      X = calloc(n, sizeof(double));
      double *Y;
      Y = calloc(n, sizeof(double));
      double *N;
      N = calloc(n, sizeof(double));
      for (i = 0;i<n;i++){
          fscanf(fichier, "%lf %lf", &X[i],&Y[i]);
          printf ("%lf %lf\n", X[i],Y[i]);
      }
     differences_divisees (N,X,Y,n-1);
     printf ("%g %g\n", x ,eval_p_dd (x,N,X,Y,n-1));
     fclose(fichier);

    }
    else
    {
      printf("Impossible d'ouvrir le fichier exo4.dat\n");
    }

    for (k = 0; k<= 1000.0;k++)
    {
      xk1 = (2007 + ((10*k)/1000));
      printf ("%g\n", xk1);
    }


  return 0;
}
