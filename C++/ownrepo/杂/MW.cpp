#include<iostream>
#include<windows.h>
using namespace std;
int main ()
{
	HDC dng=GetDC(NULL);
	COLOR c=GetPixel(dng,10,150);
	cout<<"("<<(int)GetRValue(c)<<","<<(int)GetGValue(c)<<","<<(int)GetBValue(c)<<")";
	ReleaseDC(NULL,dng); 
	return 0;
}

