#include <typeinfo>
#include <iostream> // for cout
using namespace std; // for cout
int main(){
    bool b;
    char c;
    signed char a;
    unsigned char h;
    cout<<"bool: \""<<typeid(b).name()<<"\""<<endl;
    cout<<"bool: \""<<typeid(c).name()<<"\""<<endl;
    cout<<"bool: \""<<typeid(a).name()<<"\""<<endl;
    cout<<"bool: \""<<typeid(h).name()<<"\""<<endl;



    return 0;
}
