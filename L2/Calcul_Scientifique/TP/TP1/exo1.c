#include <stdio.h>
#include <math.h>

double P_exo1 (double xk){
float p; 
       
        p = (pow(xk,3)+2.0*pow(xk,2)-5.0*xk -6.0);  

 return p;
}


int main () {
    float xk1;
    float k ;
for (k = 0; k<= 1000.0;k++){


    xk1 = (-5.0+(10.0*k/1000.0));
     printf ("%g %g\n", xk1 ,P_exo1(xk1));
}

}