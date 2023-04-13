#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sin_approx(double x,int n){
float un1 = 1; 
float resultat; 


for (int i=1;i<n;i++)
    {
      un1 = (pow(-1,i)*(pow(x,2) /((2*i+1 )*(2*i)))*un1);
    resultat = resultat + un1;
    }
 return resultat;
}




int main()
{
  float A = M_PI ;
  float B = (M_PI/6) ;
  float C = 0.0;
  float D = 10*M_PI;
  float comparaison ;
  float resultatFonction;

  int N1;
  double x1 = B ;

  printf( " Saisir la valeur de n : ");
  scanf("%d", &N1);

//printf( " Saisir la valeur de x : ");
 // scanf("%lf", &x1);

printf("%lf",sin_approx( x1, N1));

printf (" avec la fonction sinus le resultat est : %lf\n ", sin (x1));

resultatFonction = sin_approx( x1, N1);
comparaison = (sin (x1) - resultatFonction);

printf (" l\'erreur est de : %lf\n ", comparaison);

 
}
