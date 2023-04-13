#include <stdio.h>
#include <stdlib.h>
#define FAUX 0
#define VRAI 1
typedef int   BOOLEEN;

typedef struct message
{
    int sonIdentifiant;
    char*  sonContenu ;
    BOOLEEN messageVide;
    int sonDestinataire;
    BOOLEEN messageTransmis;
    BOOLEEN messageRecu;


} _message;

typedef struct message * MESSAGE;

MESSAGE creer();

MESSAGE editer (MESSAGE unMessage, char* unContenu);

MESSAGE envoyer (MESSAGE unMessage, int unDestinataire);

MESSAGE accuserReception (MESSAGE unMessage);

int identifiant (MESSAGE unMessage);

char* contenu (MESSAGE unMessage);

int destinataire (MESSAGE unMessage);

BOOLEEN estVide(MESSAGE unMessage);

BOOLEEN estTransmis(MESSAGE unMessage);

BOOLEEN estRecu(MESSAGE unMessage);