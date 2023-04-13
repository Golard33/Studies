#include <cstdio> // for printf
namespace poo{
    int var;
    void fct() {
      printf("poo::fct(): %d\n",var);
    }
}
int main(){
  poo::var=1;
  printf("poo::var: %d\n",poo::var);
  poo::fct();

  return 0;
}
