#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messageAlarme.c"

int main(int argc, char *argv[])
{
  MESSAGE unMessage;
  int succes;
  int unDestinataire;
  char* unContenu;
  /* Allocation mémoire et vérification */

  unMessage = malloc( sizeof( struct message ) );
  if( unMessage == NULL )
  {
    printf("Allocation impossible \n");
    exit(EXIT_FAILURE);
  }
  /* Vérifier l’implémentation du constructeur creer() */
  unMessage = creer () ;
  /* Initialiser l'indice succes */
  succes= 1;

  /* Vérification avec l’accesseur estVide */
  /* Vérifier la propriété : estVide (unMessage) = True */
  if (estVide(unMessage)== FAUX )succes = 0;

  /* Vérification avec l’accesseur estTransnmis */
  /* Vérifier la propriété : estTransmis (unMessage) = false */
  if(estTransmis(unMessage) == VRAI )succes = 0; 

  /* Vérification avec l’accesseur estRecu */
  /* Vérifier la propriété : estRecu (unMessage) = false */
  if(estRecu(unMessage) == VRAI ) succes = 0; 

  /* Bilan de la vérification */

  if (succes !=1 )
  {   
    printf ("\n Implémentation incorrecte du constructeur Creer() ");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }

  // vérification de l'implementation du modificateur Editer ()

  succes = 0; // réinitialisation de la variable succes

  printf ("rentrer le message à editer\n");
  unContenu = malloc (sizeof (unContenu));

  scanf(" %s ", unContenu); 
  // PROBLEME au niveau du scanf, il faut rentrer 2 fois la meme chose pour que le programme aille au bout de la vérification
  while(getchar() != '\n');

  editer(unMessage, unContenu);
  free(unContenu);

  if ((!estVide(unMessage))== VRAI )succes++;

  if (identifiant(editer (unMessage, unContenu))== identifiant (unMessage))succes++;

  if (contenu (editer (unMessage, unContenu))== unContenu) succes++;

  if (succes !=3 )
  {   
    printf ("\n Implémentation incorrecte du modificateur éditer() ");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }

  // vérification de l'implementation du modificateur envoyer ()

  succes = 0; // réinitialisation de la variable succes

  printf ("rentrer un destinataire (un entier) pour envoyer le message\n");
  scanf(" %d ", &unDestinataire);
  // PROBLEME au niveau du scanf, il faut rentrer 2 fois la meme chose pour que le programme aille au bout de la vérification
  while(getchar() != '\n');

  envoyer (unMessage, unDestinataire);

  if (destinataire(envoyer(unMessage, unDestinataire)) == unDestinataire )succes++;

  if (estTransmis(envoyer (unMessage, unDestinataire)) == VRAI) succes++;

  if (contenu(envoyer (unMessage, unDestinataire)) == contenu (unMessage))succes++;

  if (identifiant(envoyer(unMessage, unDestinataire)) == identifiant(unMessage) ) succes++ ;

  if (succes !=4 )
  {   printf ("\n Implémentation incorrecte du modifacteur envoyer() ");
      printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
      exit(EXIT_FAILURE);
  }

  /* réinitialiser la variable « succès » */

  succes =0;

  // vérification de l'implementation du modificateur accuserReception 

  accuserReception (unMessage);

  if(estRecu(unMessage) == VRAI) succes++;

  if(destinataire (unMessage) == unMessage -> sonDestinataire) succes++;

  if(identifiant (unMessage) == unMessage -> sonIdentifiant) succes++;

  if(contenu (unMessage) == unMessage -> sonContenu) succes++;

  if (succes !=4 )
  {   
    printf ("\n Implémentation incorrecte du modificateur AccuserReception() ");
    printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
    exit(EXIT_FAILURE);
  }

  printf("L'implementation du type abstrait est vérifiée\n");
  printf("Fin normale de la vérification de l'implémentation du type abstrait");
  return EXIT_SUCCESS;


}
