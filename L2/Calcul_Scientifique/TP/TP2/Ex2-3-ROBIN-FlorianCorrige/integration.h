#ifndef INTEGRATION_H
#define INTEGRATION_H


double integrationPtMilieuComposite (double (*f)(double), double a, double b,int N);
double integrationPtMilieu (double (*f) (double), double a, double b);
double integrationTrapezeComposite (double (*f) (double), double a, double  b, int N);
double integrationSimpson(double (*f) (double) , double a, double b, int N);
double boole(double (*f)(double), double a, double b, int N);
#endif