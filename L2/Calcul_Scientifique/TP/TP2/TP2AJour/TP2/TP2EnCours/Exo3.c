#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1(double x){
  double y;
  y = sqrt(1+pow((3*pow(x,2)),2));
  return y;
}

double f2(double x){
  return sqrt(1 + pow((sin(x)/cos(x)),2));
}

double f3(double x){
  return sqrt(1+pow((1/(1+pow(x,2))),2));
}


double integrationSimpson(double (*f)(double), double a, double b, int N){
	double h, xA, xB, xC, l;
	double r = 0;
	for (int i = 0; i < N; i++) {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		xC = 0.5*(xA+xB);
		l = (xB - xA);
		r += (h/6)*(f(xA)+(4*f(xC))+f(xB));
}
return r;
}

int main(){
  int N = 32;
  double a1,a2,a3 = 0;
  double b1 = 1;
  double b2 = M_PI/4;
  double b3 = 1;
  double c1 = integrationSimpson(*f1,a1,b1,N);
  printf("L'intégrale de simpson pour longueur a sur [0,1] est : %lg\n",c1);
  double c2 = integrationSimpson(*f2,a2,b2,N);
  printf("L'intégrale de simpson pour longueur b sur [0,pi/4] est : %lg\n",c2);
  double c3 = integrationSimpson(*f3,a3,b3,N);
  printf("L'intégrale de simpson pour longueur c sur [0,1] est : %lg\n",c3);
}
