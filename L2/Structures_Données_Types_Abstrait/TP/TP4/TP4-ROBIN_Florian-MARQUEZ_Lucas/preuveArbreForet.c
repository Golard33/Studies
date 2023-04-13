#include <stdio.h>
#include <stdlib.h>
#include"arbreForet.h"

int main(){

	ARBRE A = arbreVide(); /* Test création arbre */

	if (estArbreVide(A)) printf("test arbre vide correct.\n"); /* test arbre vide */
	else printf("Arbre non vide.\n");

	FORET F = foretVide(); /* Test création foret */

	if (estForetVide(F)) printf("test forêt vide correct.\n"); /* test foret vide */
	else printf("Foret non vide.\n");

	if (racine(A)==NULL) printf("test racine arbre correct.\n"); /* test racine arbre */
	else printf("Implémentation racine non correct.\n");

	if(nombreArbres(F)==0) printf("test nombre arbres forêt correct.\n"); /* test nombre arbres foret */
	else printf("Implémentation nombre arbre non correct.\n");

	planter(F,0,A); /* test planter */
	if(nombreArbres(F)==0) printf("test planter correct.\n");
	else printf("planter non correct\n");
	free(A);

	ARBRE B = iemeArbre(F,0); /* test ieme Arbre  */
	if (estArbreVide(B)) printf("test ième arbre correct.\n");
	else printf("ième arbre non correct\n");

	ARBRE C = construire(1,F); /*  test construire */
	if (listeSousArbres(C)==NULL) printf(" test construire correct.\n"); /*  test liste */
	else printf("construire ou liste non ok\n");
	
/*erreur segmentation (core dumped) à cause de la ligne 123 de "arbreForet.c"
}