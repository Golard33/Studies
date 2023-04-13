#include "Pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

PILE pileVide()  /*  création d’une pile vide*/
{
  PILE *pile = malloc(sizeof(*pile)); //allocation memoire Pile
  if (!(pile == NULL)) //Vérification allocation
  {
  	printf("OK, Pile P initialise\n");
  }
  return *pile;
}


PILE depiler(PILE *pile) /* retrait de l'element au sommet*/
{
  PILE tmp = *pile;
  *pile=tmp->suiv;
  free(tmp); /*liberation memoire*/
  printf("Element depile\n");
  return *pile;
}


PILE empiler(PILE *pile, int Elt)	/* ajout d'un element à la pile */
{
  PILE tmp = malloc(sizeof(CelluleP)); //allocation memoire Cellule
  tmp->val = Elt;  //initialisation Cellule
  tmp->suiv = *pile;
  *pile=tmp;
  printf("Element empile\n");
  return *pile;

}



int estVideP(PILE pile) /* tester si la pile est vide*/
{
  return(pile==NULL);
}


int sommet(PILE pile) /* acces au sommet de la pile */
{
  return(pile->val);
}
