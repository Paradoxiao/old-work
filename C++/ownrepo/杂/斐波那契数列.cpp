#include<bits/stdc++.h>
using namespace std;
int main()
{

long long a=0,b=0,c=1,n;
cin>>n;
for(int i=1;i<=n-1;i++)
{
a=b;
b=c;
c=a+b;
}

cout<<c;


return 0;
}
