#include <math.h>
#include <stdio.h>

int main()
{
  int n;
  float resultat ;
  float a0=0;
   float b0=0;
  float a = a0;
  float b = b0;
 float c;
 float d;
 float A;

  printf( " Saisir la valeur de n : ");
  scanf("%d", &n);

  printf( " Saisir la valeur de c : ");
  scanf("%f", &c);

  printf( " Saisir la valeur de d : ");
  scanf("%f", &d);

  for (int i=0;i<n;i++)
    {
      A = a;
      a = pow(a,2) - pow (b,2)+ c ;
      
      b = 2*A*b + d ;
    }


resultat = sqrt ((pow (a,2)+ pow(b,2)));


  printf(" a_%d=%f\n",n,a);
  printf(" b_%d=%f\n",n,b);
  printf(" resultat_%d=%f\n",n,resultat);
}
