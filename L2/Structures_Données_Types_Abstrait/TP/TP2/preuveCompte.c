#include <stdio.h>
#include <stdlib.h>
#include "compte.c"

int main(int argc, char *argv[])
{
  compte c;
  int succes;
  float s1;
  /* Allocation mémoire et vérification */

  c = malloc( sizeof( struct un_compte) );
  if( c == NULL )
  {
    printf("Allocation impossible \n");
    exit(EXIT_FAILURE);
  }
  /* Vérifier l’implémentation du constructeur creer() */
  c = COMPTE_creer () ;
  /* Initialiser l'indice succes */
  succes= 1;

  /* Vérification avec l’accesseur test_cloturer */
  /* Vérifier la propriété : test_cloturer(c ) = True */
  if ( test_cloturer(c) == VRAI) succes = 0;

  /* Vérification avec l’accesseur soldeCompte */
  /* Vérifier la propriété : soldeCompte (c) = 0.0 */
  if (soldeCompte (c ) != 0.0) succes = 0;

  /* tester si le nom du compte est vide ou non */
  if (Titulaire_compte1(c) != NULL ) succes =0;

  /* Bilan de la vérification */
  if (succes !=1 )
  {   
    printf ("\n Implémentation incorrecte du constructeur Nul() ");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }
   /* réinitialiser la variable « succès » */
  succes =0;

  // Vérification de l'implémentation du constructeur crediter()
  printf("Entrez le montant à créditer : \n");
  scanf("%f",&s1);
  while(getchar() != '\n');
      
  crediter(c,s1);

  /*Vérification avec test_cloturer()*/
  /* on teste la précondition */
  if (!test_cloturer(c) == FAUX) succes = 1;

  /*Vérification avec soldeCompte() et Titulaire_compte1 des axiomes : */
  if(soldeCompte(c)+s1==(soldeCompte (crediter(c,s1)))) 
  {
    succes++;
  }

  if((Titulaire_compte1(crediter(c,s1)) ==Titulaire_compte1(c))) 
  {
    succes++;
  }

  if (succes!=2) 
  {
    printf("\n implémentation incorrecte du constructeur crediter() ");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }
  // Vérification de l'implémentation du constructeur _debiter()
  printf("Entrez le montant à débiter : \n");
  scanf("%f",&s1);
  while(getchar() != '\n');
  c= debiter(c,s1);
  succes=0;

  if (!test_cloturer(c) == FAUX) succes = 1;

  /*Vérification avec soldeCompte() et Titulaire_compte1 des axiomes : */
  if(soldeCompte(c)-s1 == soldeCompte (debiter(c,s1))) 
  {
    succes++;

  }
  if(Titulaire_compte1(debiter(c,s1))==Titulaire_compte1(c))
  {
    succes++;
  }

  if (succes!=2)
  {
    printf("\n implémentation incorrecte du constructeur débiter");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }

  // Vérification de l'implémentation du constructeur cloturer()
  succes=0;
  c->soldeCompte=0.0;   // remise à zéro du solde

  /* verification des preconditions pour le modificateur cloturer*/
  if (!test_cloturer(c) == FAUX) succes = 1;

  if (soldeCompte(c) != 0.0) succes = 1;

  /* Vérification avec estCloture(), solde() et titulaire() des axiomes
 .  estCloture(cloturer(c1))
 . solde(cloturer(c1)) = 0
 . titulaire(cloturer(c1)) = titulaire(c1) */

  if((test_cloturer(cloturer(c)))==VRAI) 
  {
    succes++;
  }

  if(soldeCompte (cloturer(c))==0)
  {
    succes++;
  }

  if (Titulaire_compte1 (cloturer(c))== Titulaire_compte1 (c))
  {
    succes++;
  }

  if (succes!=3) {
    printf("\n implémentation incorrecte du constructeur cloturer");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }

  printf("L'implementation du type abstrait est vérifiée\n");
  printf("Fin normale de la vérification de l'implémentation du type abstrait");
  return EXIT_SUCCESS;
}
