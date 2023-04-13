#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define	        MaxSize   10
#define 	FAUX   	  0
#define 	VRAI   	  1
typedef         int 	BOOLEEN;   	
typedef   struct un_polynome 
          {
          int    sonDegre ;
	  float  sonCoefficient[MaxSize];
          }  polynome;

typedef  struct un_polynome *  POLYNOME;   


int Degre(POLYNOME p);  /* calcul  degré d’un polynôme */
float Coefficient(POLYNOME p, int i) ; /* calcul coefficient de rang i d’un polynôme */
BOOLEEN estNul(POLYNOME  p);  /* tester si le polynôme  est nul*/
POLYNOME Nul();  /*  création d’un polynôme nul*/
POLYNOME Construire(POLYNOME p1, float a0);  /* construire un polynôme */