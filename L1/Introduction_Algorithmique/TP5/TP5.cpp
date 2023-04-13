#include <iostream>
using namespace std;
#define tailleJeu 3
void initialiserGrille (int mat[][&tailleJeu]){
for (int i = 0; i <tailleJeu; i++) {
  for (int j = 0; j <tailleJeu; j++) {
    mat [i][j]=0;
    }
  }

}


void afficherGrille(int mat[][tailleJeu]){
  for (int i = 0; i <tailleJeu; i++) {
      cout << endl;
    for (int j = 0; j <tailleJeu; j++) {
      cout << mat [i][j]<< " ";
     }
   }
 }

int main(){
 int grille[tailleJeu][tailleJeu] ;
 initialiserGrille(grille) ; /* appel au sous-programme d’affichage */
 afficherGrille (grille) ;
 int n,m;
 int joueur = 0;

 std::cout << "quel joueur commence, saisir la valeur 1 ou 2" << '\n';
 std::cin >> joueur;
 int cpt = 0;

   while (cpt <= (tailleJeu*tailleJeu)) {
     std::cout << "sélectionner la case de la matrice [i] [j] avec n et m" << '\n';
     std::cin >> n;
     std::cin >> m;
     mat [n][m]= joueur;
     cpt = cpt+1;
     if (joueur == 1) {
       joueur = 2;
      }
     else{
       joueur = 1;
      }
   }
return 1;
}
