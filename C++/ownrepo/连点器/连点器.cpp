#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <typeinfo>
using namespace std;
int i;
int main()
{
	cout << "��ɾ������ʼ���㣬ESC���˳�" << endl;
   
    cout <<"������� 1"<<endl;
    cout <<"�Ҽ����� 2"<<endl;
    cout <<"������� 3"<<endl;
    cin >> i;
    
    double times;
    
    cout << "�������������(ms��0.001s��)��";
    cin >> times;
    
    if (i==2)
	{
    while (true)
    {
        if (typeid(times) != typeid(double))
        {
            cout << "������������룺";
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
            cout << "������������룺";
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
            cout << "������������룺";
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

