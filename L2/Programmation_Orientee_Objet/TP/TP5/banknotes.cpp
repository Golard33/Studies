#include <iostream> // for cout
using namespace std; // for cout
#include <limits> // for numeric_limits

int main() {
  int a = 0, b = 0 ,c = 0,d = 0,e = 0, f = 0, g =0, i = 1, banknote = 0;
  while(i!=0){
    cout<<"banknote:";
    cin>>banknote;
    if(cin.bad() or cin.eof() or cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            i=-1;
    }
    switch (banknote) {
      case -1:cout<<"exit"<<endl;return 1;
      case 5:a++;break;
      case 10:b++;break;
      case 20:c++;break;
      case 50:d++;break;
      case 100:e++;break;
      case 200:f++;break;
      case 500:g++;break;
      default:cerr<<"invalid banknote value"<<endl;
    }
    cout<<a<<" banknote(s) of 5 euros"<<endl;
    cout<<b<<" banknote(s) of 10 euros"<<endl;
    cout<<c<<" banknote(s) of 20 euros"<<endl;
    cout<<d<<" banknote(s) of 50 euros"<<endl;
    cout<<e<<" banknote(s) of 100 euros"<<endl;
    cout<<f<<" banknote(s) of 200 euros"<<endl;
    cout<<g<<" banknote(s) of 500 euros"<<endl;
  }
  return 0;
}
