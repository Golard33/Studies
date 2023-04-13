#ifndef ARBREFORET_H
#define ARBREFORET_H
#include <stdio.h>
#include <stdlib.h>
#define FAUX 0
#define VRAI 1
#define MAX 40

typedef int ELEMENT;

typedef int BOOLEEN;

typedef struct noeud{
      ELEMENT etiquette ;
      int nb_sous_arbres ;
      struct noeud* sous_arbre[MAX];
} * NOEUD; /* type concret des nœuds */

typedef NOEUD ARBRE ; /*type concret des arbres */


struct tree {
      ARBRE un_arbre ;
      struct tree * suivant;
} ;

typedef struct tree * FORET; /* type concret des forêts*/



/* créer un arbre vide */
ARBRE arbreVide();

/* construire un arbre A à partir d’un nœud o et d’une forêt F */
ARBRE construire(NOEUD o, FORET F);

/* tester la vacuité d’un arbre */
BOOLEEN estArbreVide(ARBRE A);

/* donner la racine d’un arbre A */
NOEUD racine(ARBRE A);

/* créer une forêt vide */
FORET foretVide();

/* tester la vacuité d’une forêt*/
BOOLEEN estForetVide(FORET F);

/* donner la foret composée des sous_arbres d’un arbre A*/
FORET listeSousArbres(ARBRE A);

/* ajouter un arbre au rang i dans une foret F */
FORET planter(FORET F, int i, ARBRE A);

/* nombre de sous arbres d’une forêt F */
int nombreArbres(FORET F);

/* chercher l’arbre de rang i dans la foret F */
ARBRE iemeArbre(FORET F, int i);


#endif
