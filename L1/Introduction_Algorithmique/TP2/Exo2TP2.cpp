#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* retourne un nombre compris entre 0 et maxi-1 */
int nombreAlea(int maxi) {
	srand(time(NULL));
	return(rand() % maxi);
}
int main() {
int NbMyst ;
int nb;
int cpt;

  NbMyst = nombreAlea(10);
  std::cout << "donner un nb entre 0 et 9"<<'\n' ;
  std::cin  >> nb;
  cpt = 1;
  while (nb!=NbMyst) {
        if (nb<NbMyst) {
        std::cout << "nombre trop petit"<< '\n';
         }
        else {
         std::cout << "nb trop grand"<< '\n';
         }
         std::cout << "donner un nombre entre 0 et 9" << '\n';
         std::cin >> nb;
         cpt = cpt+1;
    }
   std::cout << "gagner en"<< cpt <<"coups";
}
