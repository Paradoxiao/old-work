#include<iostream>
#include<windows.h>
using namespace std;
struct point
{
	POINT data;
	point *next,*last;
	point(POINT data)
	{
		this->data=data;next=NULL;last=NULL;
	}
};
class points
{
	private:
		long n;
		long nn;
	public:
		point* now;
		points(void)
		{
			n=0;nn=0;now=NULL;
		}
		~points(void)
		{
			point* temp=now->next;
			while(now!=temp)
			{
				delete now;
				now->next=NULL;
				now->last=NULL;
				now=temp;
			}
			delete now;
		}
		void add(POINT data)
		{
			point* newpoint=new point(data);
			if(!now)
			{
				now=newpoint;
				now->last=now;
				now->next=now;
				n++;nn++;
				cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
				return;
			}
			point* temp=now->next;
			now->next=newpoint;
			newpoint->last=now;
			temp->last=newpoint;
			newpoint->next=temp;
			now=newpoint;
			n++;nn++;
			cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
		}
		void next(void)	
		{
			now=now->next;
			if(nn<n)
			{
				nn++;
				cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
			}
			else
			{
				nn=1;
				cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
			}
		}
		void last(void)
		{
			now=now->last;
			if(nn>1)
			{
				nn--;
				cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
			}
			else
			{
				nn=n;
				cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
			}
		}
		void del(void)
		{
			point* temp=now->last;
			if(n<=1)
			{
				cout<<"error\a"<<endl;
				return;
			}
			now->last->next=now->next;
			now->next->last=now->last;
			now->next=NULL;
			now->last=NULL;
			delete now;
			now=temp;
			n--;nn--;
			cout<<"总节点数："<<n<<"  "<<"当前节点"<<nn<<endl;
		}			
};
class key
{
	private:
		bool lock;
	public:
		int vk;
		key(int data)
		{
			vk=data;
			lock=false;
		}
		bool press(void)
		{
			bool down=GetAsyncKeyState(vk)&0x8000;
			if (down and !lock)
			{
				lock=true;
				return true;
			}
			else if (!down and lock)
			{
				lock=false;
				return false;
			}
			else
			{
				return false;
			}
		}
};

int main ()
{
	points pp;key escape(VK_ESCAPE),space(VK_SPACE),down(VK_DOWN),up(VK_UP),del(VK_DELETE);POINT temp={0,0};
	while(true)
	{
		if (space.press())
		{
			GetCursorPos(&temp);
			pp.add(temp);
		}
		if (down.press())
		{
			pp.next();
			SetCursorPos(pp.now->data.x,pp.now->data.y);
		}
		if (up.press())
		{
			pp.last();
			SetCursorPos(pp.now->data.x,pp.now->data.y);
		}
		if (del.press())
		{
			pp.del();
			SetCursorPos(pp.now->data.x,pp.now->data.y);
		}
		if (escape.press())break;
	}
	return 0;
}

