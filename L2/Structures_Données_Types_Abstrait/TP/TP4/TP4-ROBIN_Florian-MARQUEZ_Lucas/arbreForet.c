#include "arbreForet.h"

/* créer un arbre vide */
ARBRE arbreVide() {
  return (NULL);
}

/* construire un arbre A à partir d’un nœud o et d’une forêt F */
ARBRE construire(NOEUD o, FORET F)
{
  FORET foret = F;
  ARBRE A;
  int nombre, i;
  A = (ARBRE) malloc(sizeof(struct noeud)) ;
  A->etiquette = o-> etiquette;
  A->nb_sous_arbres = nombreArbres(F);
  nombre= A->nb_sous_arbres;
  for(i=1 ; i<= nombre ; i++)
  {
    A->sous_arbre[i] = foret->un_arbre; foret = foret->suivant ;
  }
  return (A);
}

/* tester la vacuité d’un arbre */
BOOLEEN estArbreVide(ARBRE A) {
  return (A == NULL);
}

/* donner la racine d’un arbre A */
NOEUD racine(ARBRE A) {
  return (A);
}

/* créer une forêt vide */
FORET foretVide() {
  return (NULL);
}

/* tester la vacuité d’une forêt*/
BOOLEEN estForetVide(FORET F) {
  return (F == NULL);
}

/* donner la foret composée des sous_arbres d’un arbre A*/
FORET listeSousArbres(ARBRE A)
{
  FORET F, foret ;
  int i,n;
  F= (FORET) malloc(sizeof(struct tree)) ;
  n= A->nb_sous_arbres;
  if(n == 0) {
      return (foretVide());
  }
  else
  {
      foret = F;
      for(i=1; i<= n; i++ )
      {
          foret->un_arbre = A->sous_arbre[i];
          foret->suivant = (FORET) malloc(sizeof(struct tree)) ;
          foret = foret->suivant ;
      }
      foret = NULL;
  }
return (F);
}

/* ajouter un arbre au rang i dans une foret F */
FORET planter(FORET F, int i, ARBRE A)
{
    int k;
    FORET la_premiere, la_nouvelle, actuelle, la_precedente;
    /* cas d’insertion à la première place */
    if(i==1)
    {
        /*la_premiere= malloc(sizeof(struct tree));*/
	la_premiere= (struct tree*) malloc(sizeof(struct tree)) ;
        la_premiere->un_arbre = A;
        la_premiere->suivant = F ;
        F = la_premiere;
    }
    else
    /* cas général */
    {
        actuelle= F;
        for(k=1 ; k<=i-1 ; k++) {
            la_precedente=actuelle ;
            actuelle=actuelle->suivant ;
        }
        la_nouvelle= ((struct tree*) malloc(sizeof(struct tree))) ;
        la_precedente->suivant = la_nouvelle ;
        la_nouvelle->un_arbre= A ;
        la_nouvelle->suivant= actuelle ;
    }
    return (F);
}

/* nombre de sous arbres d’une forêt F */
int nombreArbres(FORET F)
{
    FORET foret = F;
    int nombre =0;
    while(foret != NULL) {
      nombre++;
      foret = foret->suivant;
    }
    return (nombre) ;
}

/* chercher l’arbre de rang i dans la foret F */
ARBRE iemeArbre(FORET F, int i)
{
  int k;
  FORET foret = F;
  if(i==1){
      return (foret->un_arbre) ;
  }
  else {
      for(k=1; k<= i-1; k++){
          foret= foret->suivant;
      }
      return (foret->un_arbre);
  }
}
