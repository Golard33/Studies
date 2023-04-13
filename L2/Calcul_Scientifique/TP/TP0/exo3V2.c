#include <math.h>
#include <stdio.h>


double sin_approx(double x,int n){
float un1; 
float un;
float resultat;

for (int i=0;i<n;i++)
    {
       un1 = (pow(x,2) /((2*n )*(2*n-1)));
      un = (pow(-1,n)*(pow(x,2) /((2*n+1 )*(2*n)))*un1);
      resultat = resultat + un;
    }
 return resultat;
}




int main()
{
  double N1;
  int x1;


  printf( " Saisir la valeur de n : ");
  scanf("%lf", &N1);

printf( " Saisir la valeur de x : ");
  scanf("%d", &x1);

printf("%f",sin_approx( x1, N1));

}
