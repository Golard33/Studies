#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define 	FAUX   	  0
#define 	VRAI   	  1

typedef struct CellF
  {
    int val;
    struct CellF *suivF;
  } CelluleF;

typedef struct
  {
    CelluleF *tete;
    CelluleF *queue;
  } FIL;

FIL fileVide();
FIL enfiler(FIL *file, int Elt);
FIL defiler(FIL *file);
int estVideF(FIL file);
int premier(FIL file);


#endif
