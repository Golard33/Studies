#ifndef _MATRICEH
#define _MATRICEH

void afficheVec(double *x, int n);
void afficheMat(double *A, int n);
void prodMatVec(double *A, double *x, double *y, int n);
void remontee(double *U, double *y, double *x, int n);
void descente(double *L, double *y, double *x, int n);


#endif //_MATRICEH
