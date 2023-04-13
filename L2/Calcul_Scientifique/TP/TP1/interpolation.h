#ifndef INTERPOLATION_H
#define INTERPOLATION_H


double base_lagrange (double x, int i, double *X, int n);
double eval_p (double x, double *X, double *Y, int n);
void differences_divisees (double *N, double *X, double *Y, int n);
double eval_p_dd (double x, double *N, double *X, double *Y, int n);
 #endif