#ifndef _MATRICEH
#define _MATRICEH

void afficheVec(double *x, int n);
void afficheMat(double *A, int n);
void prodMatVec(double *A, double *x, double *y, int n);
void prodMatMat(double *A, double *B, double *C, int n);
void descente (double *L, double *b, double *y, int n);
void remontee (double *U, double *y, double *x, int n);
void decompositionLU(double *A, double *L, double *U, int n);
void resolutionSystLin(double *A, double *b, double *x, int n);
void inverse(double *A, double *B, int n);
void inverse_opt(double *A, double *B, int n);

#endif 