#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "integration.h"

double f (double x){
	return sin(x);
}

int main(){
	double a, b, m, t, s;
	int N = 1;
	a = 0;
	b = M_PI;
	while (N < 8192) {
		N *= 2;
		m = integrationPtMilieuComposite (f,a,b,N);
		t = integrationTrapezeComposite(f,a,b,N);
		s = integrationSimpson(f,a,b,N);
		printf("%d	%lf	%lf	%lf	\n", N, fabs(2-m), fabs(2-t), fabs(2-s));
	}
	return 0;
}
