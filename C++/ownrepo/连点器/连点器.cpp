#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <typeinfo>
using namespace std;
int i;
int main()
{
	cout << "按删除键开始连点，ESC键退出" << endl;
   
    cout <<"左键输入 1"<<endl;
    cout <<"右键输入 2"<<endl;
    cout <<"混合输入 3"<<endl;
    cin >> i;
    
    double times;
    
    cout << "请输入连点距离(ms（0.001s）)：";
    cin >> times;
    
    if (i==2)
	{
    while (true)
    {
        if (typeid(times) != typeid(double))
        {
            cout << "请输入连点距离：";
            cin >> times;
        }
        else { break; }
    }
    while (true)
    {
        if (GetAsyncKeyState(VK_DELETE))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(times);
            if (GetAsyncKeyState(VK_ESCAPE))break;
        }
    }
	}
	if (i==1) 
	{
		while (true)
    {
        if (typeid(times) != typeid(double))
        {
            cout << "请输入连点距离：";
            cin >> times;
        }
        else { break; }
    }
    while (true)
    {
        if (GetAsyncKeyState(VK_DELETE))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(times);
            if (GetAsyncKeyState(VK_ESCAPE))break;
        }
    }
	}
	if (i==3) 
		{
    while (true)
    {
        if (typeid(times) != typeid(double))
        {
            cout << "请输入连点距离：";
            cin >> times;
        }
        else { break; }
    }
    while (true)
    {
        if (GetAsyncKeyState(VK_DELETE))
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(times);
            if (GetAsyncKeyState(VK_ESCAPE))break;
        }
    }
	}
    return 0;
}

