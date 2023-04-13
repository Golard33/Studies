/* Syracuse */

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,n,u;
	do
	{
    cout <<"Donner le premier terme de la suite (entier positif) : ";
	  cin >> a;
	} while (a<=0);
	u=a;
	n=0;
	cout <<"Les termes de la suite sont :"<<endl;
	while (u!=1)
	{
		if (u % 2==0)
			u=u/2;
		else
			u=3*u+1;
		n=n+1;
		cout <<"U("<< n <<") = "<< u<<endl;
	}
  return (0);
}
