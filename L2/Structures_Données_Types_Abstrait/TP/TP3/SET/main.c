#include <stdio.h>
#include <stdlib.h>
#include "set.h"


int main()
{

	int iSaisie =0;
	int longueurSET=0;
	bool iFin =false;
	bool trouve=false;
	int elt;


	Set L=NULL;
	setVide(&L);


	while(!(iFin))
	{
				system("clear");

				do{
									printf("********************************************\n");
		          		printf("***	           Menu SET	         ***\n");
		          		printf("********************************************\n");
		          		printf("**  1) Ajouter un element\n");
									printf("**  2) Afficher le SET\n");
									printf("**  3) Chercher si un element est dans le SET\n");
		          		printf("**  4) Supprimer un element\n");
									printf("**  5) Longueur du SET\n");
									printf("**  6) Quitter ?\n");
									printf("********************************************\n");
									printf("Votre choix : \n");
									scanf("%d%*c",&iSaisie);
		          		if ((iSaisie!=1)&&(iSaisie!=2)&&(iSaisie!=3)&&(iSaisie!=4)&&(iSaisie!=5)&&(iSaisie!=6))
		          		{
		          				printf("Choix incorrect, appuyez sur Entree pour continuer ! \n");
											scanf("%*c");
											system("clear");
									}

				}while((iSaisie!=1)&&(iSaisie!=2)&&(iSaisie!=3)&&(iSaisie!=4)&&(iSaisie!=5)&&(iSaisie!=6));

		        	switch(iSaisie)
								{
								case 1:
									printf("Entrez l'element à ajouter :  \n");
 								 	scanf("%d%*c", &elt);
		            	ajouter(&L, elt );
									printf("\nAppuyez sur Entree pour continuer\n");
									scanf("%*c");
								 	break;

								case 2:
									printf(" ******** Set ******** \n");
									afficher(L);
									printf("\nAppuyez sur Entree pour continuer\n");
									scanf("%*c");
								  break;

								case 3:
									printf("Entrez l'element à rechercher \n");
									scanf("%d%*c", &elt);

									trouve=appartient(L, elt);
									if(!(trouve)){
										printf("Element introuvable");
									}

									printf("\nAppuyez sur Entree pour continuer\n");
									scanf("%*c");
									break;

								case 4:
									printf("Entrez l'element à supprimer \n");
									scanf("%d%*c", &elt);
									enlever(&L, elt);
									printf("\nAppuyez sur Entree pour continuer\n");
									scanf("%*c");
 		              break;

								case 5:
									longueurSET = longueur(L);
									printf("La longueur de votre Set : %d \n", longueurSET);
 									printf("\nAppuyez sur Entree pour continuer\n");
 		              scanf("%*c");
 		              break;

							 	case 6:
									iFin = true;
 		              break;
								default:
 		              break;
								}
	}



	return 0;
}
