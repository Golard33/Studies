#include <math.h>
#include <stdio.h>

int main()
{ 
    int mois ;
  float Cdu = 200000;
  int C = 200000;
  float Ta = 0.0132; 
  int D = 20;
  float t ; 
  float interet ;
  float Ri_1 = 0; 
  double M ;

t = (pow ((1.0+Ta),(1.0/12))-1.0);

M =  ((C*t)*pow((1.0+t),(12*D))) / (pow((1.0+t),12*D)-1.0);
printf (" mensualité : %f \n", M);
printf ("\n");



  for ( mois =1;mois<=240 ;mois++)
    {
        interet = t*(C-Ri_1);
      Ri_1 = Ri_1 + (M-interet);
     Cdu=  Cdu - Ri_1 ; 

      if (mois == 1 ){
        printf (" premiere ligne du tableau");
        printf (" mois max est  : %d \n", mois);
        printf (" interet est de  : %f \n", interet);
        printf (" capital remboursé est de  : %f \n", Ri_1);
        printf (" capital du a la fin est de  : %f \n", Cdu);
        printf ("\n");
      }

if (mois == 2){
        printf (" deuxieme ligne du tableau");
        printf (" mois max est  : %d \n", mois);
        printf (" interet est de  : %f \n", interet);
        printf (" capital remboursé est de  : %f \n", Ri_1);
        printf (" capital du a la fin est de  : %f \n", Cdu);
        printf ("\n");
      }

        if ( Cdu<0){
         Cdu= 0;
        }
    }

  
 printf (" mois max est  : %d \n", mois);
 printf (" interet est de  : %f \n", interet);
  printf (" capital remboursé est de  : %f \n", Ri_1);
   printf (" capital du a la fin est de  : %f \n", Cdu);

   return (0); 
        
}