#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
    int max; 
    int i;
 do
    {
        printf(" entrer un entier positif ou nul");
    scanf("%d", &max);
    while(getchar() != '\n');

    } while (max < 0);
   


    for ( i = 0; i <= max; i++)
    {
         printf("max : %d \n",i );
    }
    
   


    return 0;
}