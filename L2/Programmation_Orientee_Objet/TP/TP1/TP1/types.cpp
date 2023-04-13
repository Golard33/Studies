#include <climits>
#include <cstdio> // for printf
int main(){
    printf("bool: %d byte(s), %d to %d\n",(int)sizeof(bool),false,true);
    printf("char: %d byte(s), %d to %d\n",(int)sizeof(char),CHAR_MIN,CHAR_MAX);
    printf("signed char: %d byte(s), %d to %d\n",(int)sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
    printf("unsigned char: %d byte(s), 0 to %d\n",(int)sizeof(unsigned char),UCHAR_MAX);
    printf("wchar_t: %d byte(s), %d to %d\n",(int)sizeof(wchar_t),WCHAR_MIN,WCHAR_MAX);
    printf("unsigned short: %d byte(s), 0 to %d\n",(int)sizeof(unsigned short),USHRT_MAX);
    printf("int: %d byte(s), %d to %d\n",(int)sizeof(int),INT_MIN,INT_MAX);
    printf("unsigned int: %d byte(s), 0 to %u\n",(int)sizeof(unsigned int),UINT_MAX);
    printf("long: %d byte(s), %ld to %ld\n",(int)sizeof(long),LONG_MIN,LONG_MAX);






    return 0;
}
