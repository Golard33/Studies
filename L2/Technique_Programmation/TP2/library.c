#include<stdio.h>
#include<limits.h>
#include<float.h>

#define name 100





 void book_printf () {
        printf ("%d \n", name);


    }

enum day_e()
    {
        lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche
    }


    struct library_s()
      {
        char nom[name];
        enum day_e days [7];
        int ndays;
        struct book_s;
        int nbooks book_s;
      }



    struct book_s()  {
    char name [100];
    char authors [10][100];
    int nauthors;
    char editeur [100];
    int year ; 
    int ISBN ; 
 
    }



int main() {

    


    struct library_s biblio1 = 
    {"science library",
     {monday, tuesday, wednesday, thursday},
      4,
         {"the C programming",
         {{"bryan W.kernighan"},{"dennis M.Ritchie"}},
         2,
         {"prentice hall"},
         1988,
         9780131103627} };
    
   



    return 0;
}