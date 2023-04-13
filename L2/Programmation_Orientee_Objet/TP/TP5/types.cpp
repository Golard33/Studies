#include <climits>
#include <cfloat>
#include <cwchar>
#include <cstdio> // for cout<<
#include <iostream> // for cout
using namespace std; // for cout
int main(){
    cout<<"bool: " <<sizeof(bool) <<" byte(s), "<< false <<" to " << true  <<endl;
    cout<<"char: " <<sizeof(char) <<" byte(s), "<< CHAR_MIN <<" to " << CHAR_MAX  <<endl;
    cout<<"signed char: " <<sizeof(signed char) <<" byte(s), "<< SCHAR_MIN <<" to " << SCHAR_MAX  <<endl;
    cout<<"unsigned char: " <<sizeof(unsigned char) <<" byte(s), 0 to " << UCHAR_MAX  <<endl;
    cout<<"wchar_t: " <<sizeof(wchar_t) <<" byte(s), "<< WCHAR_MIN <<" to " << WCHAR_MAX  <<endl;
    cout<<"unsigned short: " <<sizeof(wchar_t) <<" byte(s), 0 to " << USHRT_MAX  <<endl;
    cout<<"int: " <<sizeof(int) <<" byte(s), "<< INT_MIN <<" to " << INT_MAX  <<endl;
    cout<<"unsigned int: " <<sizeof(unsigned int) <<" byte(s), 0 to " << UINT_MAX  <<endl;
    cout<<"long: " <<sizeof(long) <<" byte(s), "<< LONG_MIN <<" to " << LONG_MAX  <<endl;







    return 0;
}
