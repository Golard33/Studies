#include <iostream> // for cout
using namespace std; // for cout
#include <limits> // for numeric_limits
int main(){
    int mark=-1;
    while((mark<0) or (mark>20)){
        cout<<"mark:";
        cin>>mark;
        if(cin.bad() or cin.eof() or cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          mark=-1;

        }

    }
    if(mark<10){
        cout<<"failing"<<endl;
    }
    else{
          if(mark<12){
            cout<<"satisfactory"<<endl;
          }
          else{
                if(mark<16){
                  cout<<"good"<<endl;
                }
                else{
                  cout<<"excellent"<<endl;
                }
              }
            }
          


    return 0;
}
