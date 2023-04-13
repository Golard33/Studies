#include <limits> // for numeric_limits
#include <iostream> // for cout
using namespace std; // for cout
int main(){
    std::numeric_limits<bool> nlb;
    numeric_limits<char> nlc;
    numeric_limits<signed char> nlsc;
    numeric_limits<unsigned char> nluc;
    numeric_limits<wchar_t> nlwc;
    numeric_limits<unsigned short> nlus;
    numeric_limits<int> nli;
    numeric_limits<unsigned int> nlui;
    numeric_limits<long> nll;
    cout<<"bool: " <<sizeof(nlb) <<" byte(s), "<< nlb.min() <<" to " << nlb.max()  <<endl;
    cout<<"char: " <<sizeof(nlc) <<" byte(s), "<< int(nlc.min()) <<" to " << int(nlc.max())  <<endl;
    cout<<"signed char: " <<sizeof(nlsc) <<" byte(s), "<< int(nlsc.min()) <<" to " << int(nlsc.max())  <<endl;
    cout<<"unsigned char: " <<sizeof(nluc) <<" byte(s), " << int(nluc.min()) <<" to " << int(nluc.max())  <<endl;
    cout<<"wchar_t: " <<sizeof(nlwc) <<" byte(s), "<< nlwc.min() <<" to " << nlwc.max()  <<endl;
    cout<<"unsigned short: " <<sizeof(nlus) <<" byte(s), 0 to " << nlus.max()  <<endl;
    cout<<"int: " <<sizeof(nli) <<" byte(s), "<< nli.max() <<" to " << nli.max()  <<endl;
    cout<<"unsigned int: " <<sizeof(nlui) <<" byte(s), 0 to " << nlui.max()  <<endl;
    cout<<"long: " <<sizeof(long) <<" byte(s), "<< nll.min() <<" to " << nll.max()  <<endl;*/







    return 0;
}
