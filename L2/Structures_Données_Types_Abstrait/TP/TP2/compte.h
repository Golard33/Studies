#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FAUX 0
#define VRAI 1
typedef int BOOLEEN;


    /*definir un compte */
typedef struct un_compte 
{
    char* Titulaire_compte;
    float soldeCompte;
    BOOLEEN Indicateur_cloture;

}COMPTE;

/* définition du type du compte : un type pointeur vers un objet de type compte */
typedef struct un_compte * compte;

/*créer un compte*/
compte COMPTE_creer ();

/*crediter compte si compte non cloturé */
compte crediter(compte c, float s1);

/*débiter le compte si solde > montant à débiter et si compte non cloturé */
compte debiter(compte c, float s1);

/*cloturer le compte si le solde est nul */
compte cloturer (compte c);

/*donner nom titulaire*/
char*Titulaire_compte1 (compte c);

/*tester si compte cloturer ou non*/
BOOLEEN test_cloturer(compte c);

/*tester si solde est nul ou non*/
float soldeCompte (compte c);