#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void pythagoras(double a, double b, double *c )
{   
   c = sqrt (pow (a,2)+ pow(b,2));
   return c;
}


int main (int argc, char *argv[])
{
    char longueur
    char longueur2;
    double ValueLongueur
    double ValueLongueur2;
    char* pointeur1;
    char * pointeur2;
    double c ;

    longueur = argv[1];
    longueur2 = argv[2];
    ValueLongueur = strtod(longueur, &pointeur1)
    ValueLongueur2 = strtod(longueur2, &pointeur2)

    if ((argc != 3) || (pointeur1 == longueur) || (pointeur2 == longueur2))
    {
        fprintf (stderr, "invalid number of argument or bad arguments in parameters \n");
        return 1;
    }
    
    pythagoras (ValueLongueur, ValueLongueur2);
    printf ("%d\n", c );

    return 0;
}œ