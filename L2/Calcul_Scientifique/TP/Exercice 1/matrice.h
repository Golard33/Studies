#ifndef _MATRICEH
#define _MATRICEH

void afficheMat(double *A, int n);
void afficheVec(double *u, int n);
void prodMatVec(double *A, double *x, double *b, int n);
void prodMatMat(double *A, double *B, double *C, int n);
void remontee(double *U, double *y, double *x, int n);
void descente(double *L, double *y, double *x, int n);
void decompositionLU(double *A, double *L, double *U, int n);
void resolutionSystLin(double *A, double *b, double *x, int n);
void inverse(double *A, double *B, int n);
void inverse_opt(double *A, double *B, int n);

#endif //_MATRICEH
