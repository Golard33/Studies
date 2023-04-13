#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "integration.h"

double f1 (double x){
  return pow(x,5);
}

double f2 (double x){
  return pow(x,6);
}

double f3 (double x){
  return sin (x);
}

int main(){
  double a, b, c1, c2, c3, c4, erreur;
  int N = 4;
  int N1 = 10;
  int N2 = 20;
  a = 0;
  b = 1;
  c1 = boole(*f1,a,b,N);
  c2 = boole(*f2,a,b,N);
  c3 = boole(*f3,a,M_PI,N1);
  c4 = boole(*f3,a,M_PI,N2);
  erreur = ((fabs(2-c3))/ (fabs(2-c4)));
  printf("Degré d'exactitude : 5 --> %lg %lg\n",c1,fabs((1.0/6)-c1));
  printf("Degré d'exactitude : 6 --> %lg %lg\n",c2,fabs((1.0/7)-c2));
  //printf("Comparaison de l'ordre de convergence avec même fonction (x²) mais avec un N différent : %lg <---> %lg\n",fabs((1.0/3)-c3),fabs((1.0/3)-c4));
  printf(" l'ordre de convergence avec la fonction sinus x est de : %lg \n",log2(erreur));
  return 0;
}