#include <cstdio> // for printf
namespace poo{
    int var;
    void fct() {
      printf("fct(): %d\n",var);
    }

}
int main(){
    using namespace poo;
    var=1;
    printf("var: %d\n",var);
    fct();



  return 0;
}
