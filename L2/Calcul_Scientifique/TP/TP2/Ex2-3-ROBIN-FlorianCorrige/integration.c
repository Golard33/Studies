#include <stdio.h>
#include <math.h>
#include "integration.h"

double integrationPtMilieu (double (*f) (double), double a, double b)
{
  double r;
  r = (b-a) * f((a+b)/2);
  return r; 
    
}

double integrationPtMilieuComposite (double (*f)(double), double a, double b,int N) 
{
  double h, somme;
  h = ((b - a)/N);
  for (int i = 0; i < N-1; i++)
  {
    somme = somme + integrationPtMilieu (f, (a+i*h), ((a+i*h)+1) );

  }
  return somme;
}



double integrationTrapezeComposite( double (*f) (double) ,double a, double b, int N){
	double h, xA, xB, l;
	double r = 0;
	for (int i = 0; i < N; i++) {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		l = (xB - xA);
		r += l*0.5*(f(xB)+f(xA));
	}
	return r;
}

double integrationSimpson(double (*f) (double) , double a, double b, int N)
{
	double h, xA, xB, xC;
  double l;
	double r = 0;
	for (int i = 0; i < N; i++) 
    {
		h = (b - a) / N;
		xA = a + i * h;
		xB = a + (i+1) * h;
		xC = 0.5*(xA+xB);
		l = (xB - xA);
		r += (h/6)*(f(xA)+(4*f(xC))+f(xB));
    }   
    return r;
}

/* pour exo 2 */

double booleComposite(double (*f)(double), double a, double b, int N){
  double h, xA, xB;
  double r = 0;
  h = (b - a) / N;
  for (int i = 0; i < N; i++) 
    {
        xA = a + i * h;
        xB = a + ( (i+1) * h );
        r += ( (xB-xA) / 90 ) * ( 7 * f(xA) + 32 * f(xA+0.25*h) + 12 * f(xA+0.5*h) + 32 * f(xA+0.75*h) + 7 * f(xB) );
    }
    return r;
}
