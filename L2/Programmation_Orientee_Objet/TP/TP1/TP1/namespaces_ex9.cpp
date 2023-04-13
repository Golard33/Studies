#include <cstdio> // for printf
namespace poo{
    int var;
    void fct() {
      printf("oop::fct(): %d\n",var);
    }
    namespace tp1{
        int var;
        void fct(){
            printf("oop::tp1::var: %d\n",var);
            
        }
    }
}
namespace oop = poo;
int main(){
    oop::var=1;
    printf("oop::var: %d\n",oop::var);
    oop::fct();
    oop::tp1::var=2;
    printf("oop::tp1::var: %d\n",oop::tp1::var);
    oop::tp1::fct();
    
    



  return 0;
}
