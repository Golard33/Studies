#include <stdio.h>
#include <stdlib.h>
#include "MessageAlarme.h"

MESSAGE creer()
{
    MESSAGE unMessage;
    unMessage = malloc(sizeof(struct message));
    if(unMessage== NULL)
    {
        fprintf(stderr,"Allocation impossible \n");
        exit(EXIT_FAILURE);
    }
    unMessage -> messageVide = VRAI;
    unMessage -> messageRecu = FAUX;
    unMessage -> messageTransmis = FAUX;
    unMessage -> sonContenu = NULL;
    unMessage -> sonIdentifiant = 0;
    unMessage -> sonDestinataire = 0;
    return unMessage;
}

MESSAGE editer (MESSAGE unMessage, char* unContenu)
{
    unMessage -> sonIdentifiant = identifiant(unMessage);
    unMessage -> sonContenu =  unContenu;
    unMessage -> messageVide = FAUX;
    return unMessage ;  
}

MESSAGE envoyer (MESSAGE unMessage, int unDestinataire)
{
    unMessage -> sonDestinataire = unDestinataire;
    unMessage -> messageTransmis = VRAI;
    return unMessage ;
}

MESSAGE accuserReception (MESSAGE unMessage)
{
    unMessage -> messageRecu = VRAI;
    printf(" accusé reception\n");
    return unMessage;
}

int identifiant (MESSAGE unMessage)
{
    return unMessage -> sonIdentifiant;
}

char* contenu (MESSAGE unMessage)
{
    return unMessage -> sonContenu;
}

int destinataire (MESSAGE unMessage)
{
    return unMessage -> sonDestinataire;
}


BOOLEEN estRecu(MESSAGE unMessage)
{
    return unMessage -> messageRecu;
}

BOOLEEN estVide(MESSAGE unMessage)
{
    return unMessage -> messageVide;
}

BOOLEEN estTransmis(MESSAGE unMessage)
{
   return unMessage -> messageTransmis;
}
