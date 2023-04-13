#include<stdio.h>
#include<limits.h>
#include<float.h>


int main()
{

    printf(" char : %ld byte(s) %d à %d \n",sizeof(char),CHAR_MIN, CHAR_MAX ); 
    printf(" signed char : %ld byte(s) %d à %d \n",sizeof(signed char),SCHAR_MIN, SCHAR_MAX );
    printf(" unsigned char : %ld byte(s) %d à %d \n",sizeof(unsigned char),0, UCHAR_MAX ); 
    printf(" short : %ld byte(s) %d à %d \n",sizeof(short),SHRT_MIN, SHRT_MAX ); 
    printf(" unsigned short : %ld byte(s) %d à %d \n",sizeof(unsigned short),0, USHRT_MAX ); 
    printf(" int : %ld byte(s) %d à %d \n",sizeof(int),INT_MIN, INT_MAX );
    printf(" unsigned int: %ld byte(s) %d à %d \n",sizeof(unsigned int),0, UINT_MAX );  
    printf(" long : %ld byte(s) %ld à %ld \n",sizeof(long),LONG_MIN, LONG_MAX ); 
    printf(" unsigned long : %ld byte(s) %d à %ld \n",sizeof(unsigned long),0, ULONG_MAX ); 
    printf(" float : %ld byte(s) %f à %f \n",sizeof(float),FLT_MIN, FLT_MAX ); 
    printf(" double : %ld byte(s) %e à %e \n",sizeof(double),DBL_MIN, DBL_MAX ); 
    printf(" long double : %ld byte(s) %Le à %Le \n",sizeof(long double),LDBL_MIN, LDBL_MAX ); 
    
    
    return 0;
} 