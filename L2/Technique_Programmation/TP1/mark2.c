#include<stdio.h>
#include<limits.h>
#include<float.h>

int main (){
float note;

    do
    {
        printf(" entrez une note entre 0 et 20 \n");
    scanf("%g", &note);

    } while ((note < 0) || (note>20));
    

    if ((note>= 0) && (note<10)){
        
    printf ("failing");
    }

    if ((note>=10) && (note <12)) {
            
    printf ("satisfactory");
    }

    if ((note>=12) && (note <16)) {
                
    printf("\r good");
    }

    if ( (note >=16) && (note <= 20) ){
                   
    printf(" excellent");
    }
            

    return 0;
}