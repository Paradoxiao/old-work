#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int a,b,c,d=0;
	POINT p,q;
	while(true)
	{
	while(true)
	{	
	if(GetAsyncKeyState(97))
	{
		GetCursorPos(&p);
		cout<<"x1="<<p.x<<" "<<"y1="<<p.y<<endl;
		a=p.x;b=p.y;
		break;
	};
	};
	while(true)
	{
	if(GetAsyncKeyState(98))
	{
		GetCursorPos(&q);
		cout<<"x2="<<q.x<<" "<<"y2="<<q.y<<endl;
		c=q.x;d=q.y;
		break;			
	};
	};
	while(true)
	{
		while(GetAsyncKeyState(99))
		{
			SetCursorPos(a,b);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			SetCursorPos(c,d);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if(GetAsyncKeyState(VK_ESCAPE))break;
	};
	};
	return 0;
}
