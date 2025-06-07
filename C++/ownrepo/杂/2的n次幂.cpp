#include <iostream>
using namespace std;
int i;
long long a,b,c;
int main()
{	
	c=a=1;
	cin>>b;
	for(i=1;i<=b;i++)
	{
	cout<<"A"<<i<<"="<<a<<endl;
	a=a+a;
	c+=a;
	}
	cout<<"Sn="<<c;
	return 0;
}

