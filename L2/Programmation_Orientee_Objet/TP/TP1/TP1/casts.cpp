#include <cstdio> // for printf
int main(){
    const int res=42l;
    printf("cast : %d \n",(int)res);
    printf("cast (functional notation): %d\n",int(res));
    printf("static cast: %d\n",static_cast<int>(res));
    return 0;
}