#include<iostream>
#include<windows.h>
using namespace std;
struct place
{
	POINT point;place* nextpl;
	place(void){nextpl=NULL;}
};
class keyevent
{
	private:
		bool lock;
	public:
		keyevent(void){lock=false;}
		bool press(int vk)
		{
			bool down=GetAsyncKeyState(vk)&0x8000;
			if(!lock and down)
			{
				lock=true;
				return down;
			}
			else if(lock and !down)
			{
				lock=false;
				return false;
			}
			return false;
		}
};
int main()
{
	place* pl=NULL;place* temp=NULL;place* newplace=NULL;keyevent key0,key1,key2;int sleep;cin>>sleep;
	while(true)
	{
		if(key1.press(97))
		{
			newplace=new place;
			GetCursorPos(&(newplace->point));
			if(!pl){pl=newplace;pl->nextpl=pl;}
			else
			{
				temp=pl->nextpl;
				pl->nextpl=newplace;
				newplace->nextpl=temp;
				pl=pl->nextpl;
			}
		}
		if(key2.press(98))GetCursorPos(&(pl->point));
		while(GetAsyncKeyState(96))
		{
			if(!pl)continue;
			pl=pl->nextpl;
			SetCursorPos(pl->point.x,pl->point.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(sleep);
		}
		if(GetAsyncKeyState(VK_ESCAPE))break;
	}
	return 0;
}

