#include<iostream>
#include<windows.h>
#include"list.h"
using namespace std;
int main()
{
	list<int> a;
	for(int i=0;i<30;i++)a.add(i);
	for(int i=0;i<30;i++)
	{
		a.next();
		cout<<a.nowNode->data<<"  ";
	}cout<<endl;
	a.del();
	a.del();
	for(int i=0;i<30;i++)a.add(i);
	for(int i=0;i<30;i++)
	{
		a.next();
		cout<<a.nowNode->data<<"  ";
	}
	return 0;
}

