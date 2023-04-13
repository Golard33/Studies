#include <stdio.h>
#include <math.h>
#include <stlib.h>
#include "interpolation.h"

const char* filename = "exo3.dat";

int main (int argc, char *argv[])
{
    FILE *in_file = fopen(filename, "r");

    if (fichier = NULL){
        int i;
        int n;
        rewind (in_file);
        fscanf(fichier, "%d", &n);
        printf( " n : %d \n", n);
        double *x;
        x = calloc(n, sizeof(double));
        double *y;
        y = calloc(n, sizeof(double)); 
        for (i = 0;i<n;i++){
            scanf(in_file, "%lf %lf", &x,%y);
        }

    }
    else {
        printf("impossible ouvrir fichier");
    }
    
    differences_divisees (N,x,y,n);
    fclose(in_file);

    return 0;
}