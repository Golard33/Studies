#include <iostream> // for cout
using namespace std; // for cout
#include <limits> // for numeric_limits
int main(){
    int i,max=-1;
    do{
        cout<<"max: ";
        cin>>max;
        if(cin.bad() or cin.eof() or cin.fail()){
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              max=-1;
        }
      }while(max<0);

    for(i=0;i<=max;i++){
        cout<<i<<endl;
    }
    return 0;
}
