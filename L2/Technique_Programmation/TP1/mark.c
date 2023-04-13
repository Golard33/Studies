#include<stdio.h>
#include<limits.h>
#include<float.h>

int main (){
float note;

    printf(" entrez une note entre 0 et 20 \n");
    scanf("%g", &note);

while ((note < 0) || (note>20))
{
    printf(" entrez une note entre 0 et 20 \n");
    scanf("%g", &note);
}

if ((note>= 0) && (note<10))
{
    printf ("failing");

}     else if ((note>=10) && (note <12)) {

        printf ("satisfactory");

    }    else if ((note>=12) && (note <16)) {

            printf("\n good");

        }   else {

                printf(" excellent");
            }

    return 0;
}