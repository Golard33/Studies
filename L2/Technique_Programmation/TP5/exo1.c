#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void mirror(char *str, char *res)
{
    int i ; 
    size_t size;
    size = strlen (str);
    for (i = 0; i< size ;i++)
    {
      /*  printf("%s \n", res[i]);*/
        res[i] = str[size -i-1];
    } 
    res[size]='\0';
}


int main (int argc, char *argv[])
{   
    char res[11];

    if ((argc != 2)|| (strlen(argv[1])>10))
    {
        fprintf (stderr, "invalid number of argument \n");
        return 1;
    }
    
    mirror(argv[1], res );
    printf ("%s\n", res);

    return 0;
}