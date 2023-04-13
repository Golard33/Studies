#include <cstdio> // for printf
#include <typeinfo>
int main(){
    bool b=true;
    char c;
    signed char a;
    unsigned char h;
    printf("bool: \"%s\"\n", typeid(b).name());
    printf("%char: \"c\"\n", typeid(c).name());
    printf("signed char: \"a\"\n", typeid(a).name());
    printf("%unsigned char: \"h\"\n", typeid(h).name());



    return 0;
}
