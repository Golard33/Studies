#include "File.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FIL fileVide()  /*  creation d une file vide*/
{
  FIL *file = malloc(sizeof(*file));
  if (!(file == NULL)) //Verification allocation
  {
  	printf("OK, la File F est allouee\n");
  }
  (*file).queue=NULL;
  (*file).tete=NULL;
  printf("OK, la File F vide est initialise\n");
  return (*file);
}

FIL defiler(FIL *file) /* retrait de l'element au sommet*/
{
  CelluleF *tmp = (*file).tete;
  if (((*file).tete)==((*file).queue)) //Verification File d'un seul element
  {
	  (*file).tete=NULL;
	  (*file).queue=NULL;
  }
  else
  {
	  (*file).tete=tmp->suivF;
  }
  free(tmp); /*liberation memoire*/
  printf("Element defile\n");
  return (*file);
}


FIL enfiler(FIL *file, int Elt)	/* ajout d'un element a la file */
{
  CelluleF *tmp = malloc(sizeof(CelluleF)); //allocation memoire Cellule
  tmp->val = Elt;
  if ((*file).queue==NULL) //Verification file vide
  {
	  (*file).tete=tmp;
  }
  else
  {
	  (*file).queue->suivF=tmp;
  }
  (*file).queue=tmp;
  printf("Element enfile\n");
  return (*file);
}



int estVideF(FIL file) /* tester si la file est vide*/
{
  return((file.tete==NULL)&&(file.queue==NULL));
}


int premier(FIL file) /* acces au premier element de la file */
{
  return(file.tete->val);
}
