#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <typeinfo>
using namespace std;
int i;
int main()
{
	while (true)
	{
	if (GetAsyncKeyState(VK_DELETE))
		{
    		for (i=0;i<10;i++)
    		{
    			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    			Sleep(10);
    		}
    	}
	}
	return 0;
}

