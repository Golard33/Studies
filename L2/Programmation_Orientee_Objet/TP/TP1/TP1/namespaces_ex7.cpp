#include <cstdio> // for printf
namespace poo{
    int var;
    void fct() {
      printf("poo::fct(): %d\n",var);
    }
    namespace tp1{
        int var;
        void fct(){
            printf("poo::tp1::var: %d\n",var);
            
        }
    }
}
int main(){
  poo::var=1;
  printf("poo::var: %d\n",poo::var);
  poo::fct();
  poo::tp1::var=2;
  printf("poo::tp1::var: %d\n",poo::tp1::var);
  poo::tp1::fct();



  return 0;
}
