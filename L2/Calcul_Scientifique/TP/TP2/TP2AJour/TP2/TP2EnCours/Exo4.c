#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1(double x){
  return pow(x,3);
}

double f2(double x){
  return tan(x);
}

double f3(double x){
  return atan(x);
}


double integrationSimpson(double (*f)(double), double a, double b, double c, double d, int N, int M){
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

}
