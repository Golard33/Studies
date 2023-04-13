#include "compte.h"
#include <stdio.h>
#include <stdlib.h>

compte COMPTE_creer ()
{
    compte c;
    c = malloc(sizeof(struct un_compte));
    if(c== NULL)
    {
        fprintf(stderr,"Allocation impossible \n");
        exit(EXIT_FAILURE);
    }
    printf("rentrer le titulaire du compte\n");
    scanf ( "%s \n" ,c -> Titulaire_compte );
     while(getchar() != '\n');
    c -> soldeCompte = 0.0;
    c -> Indicateur_cloture = FAUX;
    return c;
}

compte crediter(compte c, float s1)
{
        
    c -> soldeCompte = c -> soldeCompte +s1;
    return c;
}

compte debiter(compte c, float s1)
{
    c -> soldeCompte = c -> soldeCompte -s1;
    return c;
}

compte cloturer (compte c)
{
    c -> Indicateur_cloture = VRAI;
    return c;
}

char*Titulaire_compte1 (compte c)
{
    return  c -> Titulaire_compte;
}

BOOLEEN test_cloturer(compte c)
{
    return  c -> Indicateur_cloture;
}

float soldeCompte (compte c)
{
    return c -> soldeCompte;
}