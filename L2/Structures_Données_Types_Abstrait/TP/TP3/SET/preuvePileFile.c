#include "File.h"
#include "Pile.h"

int main(int argc, char const *argv[])
 {
   printf("*********PILE*********\n");
   printf("\n");

   PILE P;
   pileVide(); //Test fonction pileVide

   int  iVideP=estVideP(P); //Test fonction iVideP
   if(iVideP==VRAI)
   {
     printf("P EST VIDE\n");
   }

   P=empiler(&P, 4); //Test fonction empiler
   P=empiler(&P, 7); //Test fonction empiler

   int som;
   som=sommet(P); //Test fonction sommet
   printf("SOMMET avant depil : %d\n", som);

   P=depiler(&P); //Test fonction depiler

   som=sommet(P); //Test fonction sommet
   printf("SOMMET apres depil: %d\n", som);

   P=depiler(&P); //Test fonction depiler

   iVideP=estVideP(P); //Test fonction estVideP
   if(iVideP==VRAI)
   {
     printf("P EST VIDE\n");
   }



   printf("\n");
   printf("*********FILE*********\n");
   printf("\n");

   FIL F;
   fileVide(); //Test fonction fileVide

   int iVideF=estVideF(F); //Test fonction estVideF
   if(iVideF==VRAI)
   {
     printf("F EST VIDE\n");
   }

   F=enfiler(&F,5); //Test fonction enfiler

   int prem=premier(F); //Test fonction premier
   printf("PREMIER : %d\n", prem);

   F=defiler(&F); //Test fonction defiler

   iVideF=estVideF(F); //Test fonction estVideF
   if(iVideF==VRAI)
   {
     printf("F EST VIDE\n");
   }

   printf("\n");
   printf("\n");
   return (0);
 }
