#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main (int argc, char *argv[])
{   
    int taille;
    char ch;
    FILE* f = NULL;
    if (argc != 2)
    {
        fprintf (stderr, "invalid number of argument \n");
        return 1;
    }

  
    f = open(argv[0], "w");

    if( f == NULL)
    {
        return 1;
    }
    
    ssize_t write

    taille = fseek(f, 0, SEEK_END);
    fseek(f, 0, SEEK_SET);
    printf("File size = %d\n", taille); 
    printf ("path =  %s\n", argv[0]);
 
    close(f);
    return 0;
}