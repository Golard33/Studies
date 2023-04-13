#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sinus(double x){
	return sin(x);
}

double integrationPtMilieuComposite(double a, double b, int N){
	double h, xA, xB, l;
	double r = 0;
	for (int i = 0; i < N; i++) {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		l = (xB - xA);
		r += l * sinus((xA + xB)/2);
	}
	return r;
}

double integrationTrapeze(double a, double b, int N){
	double h, xA, xB, l;
	double r = 0;
	for (int i = 0; i < N; i++) {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		l = (xB - xA);
		r += l*0.5*(sinus(xB)+sinus(xA));
	}
	return r;
}

double integrationSimpson(double a, double b, int N){
	double h, xA, xB, xC, l;
	double r = 0;
	for (int i = 0; i < N; i++) {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		xC = 0.5*(xA+xB);
		l = (xB - xA);
		r += (h/6)*(sinus(xA)+(4*sinus(xC))+sinus(xB));
}
return r;
}

int main(){
	double a, b, m, t, s;
	int N = 1;
	a = 0;
	b = M_PI;
	while (N < 8192) {
		N *= 2;
		m = integrationPtMilieuComposite(a,b,N);
		t = integrationTrapeze(a,b,N);
		s = integrationSimpson(a,b,N);
		printf("%d			%lf			%lf			%lf			\n", N, fabs(2-m), fabs(2-t), fabs(2-s));
	}
	return 0;
}
