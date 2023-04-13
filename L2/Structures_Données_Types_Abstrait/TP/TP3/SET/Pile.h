#ifndef PILE_H
#define PILE_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define 	FAUX   	  0
#define 	VRAI   	  1


typedef struct CellP
	{
	  int val;
	  struct CellP *suiv ;
	} CelluleP;

typedef CelluleP *PILE;

PILE pileVide();  /*  creation d une pile vide*/
PILE empiler(PILE *pile, int Elt);	/* ajout d'un element a la pile */
PILE depiler(PILE *pile); /* retrait de l'element au sommet */
int estVideP(PILE pile); /* tester si la pile est vide*/
int sommet(PILE pile); /* acces au sommet de la pile */

#endif
