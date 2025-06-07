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
		GetCursorPos(&p);
		cout<<"x="<<p.x<<endl<<"y="<<p.y<<endl;
		a=p.x;b=p.y;
		if(GetAsyncKeyState(96))break;
				
	};
	while(true)
	{
		GetCursorPos(&q);
		cout<<"x="<<q.x<<endl<<"y="<<q.y<<endl;
		c=q.x;d=q.y;
		if(GetAsyncKeyState(97))break;
				
	};
	while(true)
	{
		while(GetAsyncKeyState(96))
		{
			SetCursorPos(a,b);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			SetCursorPos(c,d);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if(GetAsyncKeyState(VK_ESCAPE))break;
	}
	}
	return 0;
}
