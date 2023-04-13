#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef SET_H
#define SET_H

typedef int Elem;
// Structure set

typedef struct cell{
	Elem elementCell ;
	struct cell *suiv;
}Cellule;
typedef Cellule *Set;


//  Opérations

void setVide(Set *L);
int ajouter(Set *L, int Elt);
void enlever(Set *L, int Elt);
bool appartient(Set L, int Elt);
bool estVide(Set L);
int longueur(Set L);
void afficher (Set L);


#endif
