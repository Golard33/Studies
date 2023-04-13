#include <iostream>
#include <math.h>
#include <string>


#define N0 2
#define N1 1
#define N2 0
using namespace std;

int main(){
  string sSaisie;
  do{
      cout<<"\n\n***** DEBUT DE LA SEQUENCE *****"<<endl;
      cout<<"Entrez une fréquence : ";
      cin>>sSaisie;
  } while((sSaisie != "F00") && (sSaisie != "F01"));

  int count0=0, count1=0, count2=0;
  do{
      cout<<"\nEntrez une fréquence : ";
      cin>>sSaisie;
      if(sSaisie=="F10")
      {
          count0++;
      }
      if(sSaisie=="F11")
      {
          count1++;
      }
      if(sSaisie=="F12")
      {
          count2++;
      }
  } while ((sSaisie != "F20") && (sSaisie != "F21"));

  cout<<"\n***** FIN DE LA SEQUENCE *****\n\n"<<endl;
  if((count0<N0)||(count1<N1)||(count2<N2))
  {
      cout<<"*** ATTENTION ***\nLa signature ne correspond à aucun type de missile"<<endl;
      return 0;
  }
  else if (log(count0) >= log(count1 + 4*count2))
      {
          cout<<"*** Missile de type A détecté ***"<<endl;
          return 0;
      }
      else if (log(count1) >= log(2*count2))
          {
              cout<<"*** Missile de type B détecté ***"<<endl;
              return 0;
          }
          else
          {
              cout<<"*** Missile de type C détecté ***"<<endl;
              return 0;
          }
  return 0;
}
