#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set.h"

void setVide(Set *L){
	L=NULL;
}


bool estVide(Set L){
	return(L==NULL);
}


int longueur(Set L){
	Set aux;
	int compt = 0 ;

	aux=L;// copie du pointeur
	// Tant que le pointeur suiv de aux n'est pas Null
	while(aux!=NULL){
		compt++;
		aux=aux->suiv;

	}
	return(compt);
}

bool appartient(Set L, int Elt)
{

	Set aux;
	bool trouve = false;
	aux=L;

	while((aux!=NULL)&&(trouve == false)){

		if(aux->elementCell == Elt )
		{
			trouve = true;
			printf("L'element %d appartient à votre Set \n", Elt ) ;
			break;
		}

		aux=aux->suiv;

	}
	return(trouve);

}

int ajouter(Set *L, int Elt)
{

	Set aux;
	int i = 0;
	Set tmp;
	int LongueurSET = longueur(*L);
	bool Existe = appartient(*L,Elt);


	aux=*L;
	tmp=malloc(sizeof(Cellule));

	if (Existe)
	{
		printf("Element existe deja \n");
		return 0;
	}
	else {
		for(i=1;i<=LongueurSET-1;i++)
		{
			aux=aux->suiv;
		}
		if(aux!=NULL)
		{
			tmp->elementCell=Elt;
			tmp->suiv=aux->suiv;
			aux->suiv=tmp;
		}
		else
		{
			tmp->elementCell=Elt;
			tmp->suiv=*L;
			*L=tmp;
		}

		}


}

void afficher (Set L)
{
	if(estVide(L))
	{
		printf("SET vide\n");
	}

	while( L != NULL)
	{
		printf("[%d]  ", L->elementCell);
		L = L->suiv;
	}

printf("\n");

}

void enlever(Set *L, int Elt)
{
	Set aux;
	Set Asuppr;
	aux=*L;
	bool Existe = appartient(*L,Elt);
	bool trouve =false;
	if(Existe)
	{
		if((*L)->elementCell == Elt)
		{
			*L=(*L)->suiv;
			free(aux);
			trouve=true;
		}
		while(trouve == false)
		{
			if(((aux->suiv)->elementCell) == Elt )
			{
				trouve = true;
				Asuppr = aux->suiv;
				aux->suiv = Asuppr->suiv;
				free(Asuppr);
			}
			else
			{
				aux=aux->suiv;
			}
		}
		printf("Element supprime");
	}
	else
	{
		printf("Element introuvable dans le SET");
	}
}
