#include<iostream>
#include<windows.h>
using namespace std;
struct listNode{int data;listNode* nextNode;listNode(void){nextNode=NULL;data=0;}};
class list
{
	private:
		listNode* nowNode;listNode* top;
	public:
		list(int a,int b)
		{
			nowNode=NULL;top=NULL;
			for(int i=0;i<a*b;i++)
			{
				listNode* newNode=new listNode();
				if(!nowNode){nowNode=newNode;nowNode->nextNode=nowNode;}
				else
				{
					listNode* temp=nowNode->nextNode;
					nowNode->nextNode=newNode;
					nowNode=nowNode->nextNode;
					nowNode->nextNode=temp;
				}
			}
		}
		~list(void)
		{
			while(nowNode)
			{
				listNode* temp=nowNode->nextNode;
				delete nowNode;
				nowNode=temp;
			}
		}
		int view(int x,int y,int xx,int yy)
		{
			top=nowNode->nextNode;
			for(int i=1;i<y;i++)
			{
				for(int l=1;l<xx;l++)
				top=top->nextNode;
			}
			for(int i=1;i<x;i++)top=top->nextNode;
			return top->data;
		}
		void change(int a,int x,int y,int xx,int yy)
		{
			top=nowNode->nextNode;
			for(int i=1;i<y;i++)
			{
				for(int l=1;l<xx;l++)
				top=top->nextNode;
			}
			for(int i=1;i<x;i++)top=top->nextNode;
			top->data=a;
		}
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
struct xOy{int x;int y;};
bool operator==(xOy a,xOy b){if(a.x==b.x and a.y==b.y)return true;else return false;}
void up(xOy&xy,xOy&temp){temp=xy;if(xy.y>1)xy.y-=1;}
void left(xOy&xy,xOy&temp){temp=xy;if(xy.x>1)xy.x-=1;}
void down(xOy&xy,xOy&temp,xOy&area){temp=xy;if(xy.y<area.y-1)xy.y+=1;}
void right(xOy&xy,xOy&temp,xOy&area){temp=xy;if(xy.x<area.x-1)xy.x+=1;}
void press(xOy&person,xOy&preperson,xOy&box,xOy&prebox,xOy&area)
{
	if(person.y-1==preperson.y){down(box,prebox,area);if(prebox==box)person=preperson;}
	if(person.y+1==preperson.y){up(box,prebox);if(prebox==box)person=preperson;}
	if(person.x-1==preperson.x){right(box,prebox,area);if(prebox==box)person=preperson;}
	if(person.x+1==preperson.x){left(box,prebox);if(prebox==box)person=preperson;}
}
void draw(int a){if(a==0)cout<<"  ";if(a==1)cout<<"墙";if(a==2)cout<<"人";if(a==3)cout<<"箱";if(a==4)cout<<"洞";}
void fresh(xOy&person,xOy&box,xOy&base,list&area,int x,int y)
{
	system("cls");
	for(int a,b=0;b<y;b++){for(a=0;a<x;a++){area.change(0,a,b,x,y);}}
	area.change(2,person.x,person.y,x,y);area.change(3,box.x,box.y,x,y);area.change(4,base.x,base.y,x,y);
	for(int a=1;a<x;a++){area.change(1,a,1,x,y);area.change(1,a,y,x,y);}
	for(int b=1;b<y;b++){area.change(1,1,b,x,y);area.change(1,x,b,x,y);}
	for(int a,b=0;b<=y;b++){for(a=0;a<=x;a++)draw(area.view(a,b,x,y));cout<<endl;}
}
int main()
{
	xOy person,box,base,preperson,prebox,area;keyevent vkup,vkdown,vkleft,vkright;int x,y,xx,yy=0;
	cout<<"场地x:";cin>>x;cout<<"场地y:";cin>>y;xx=x+2;yy=y+2;list map(xx,yy);area.x=x;area.y=y;
	cout<<"人x:";cin>>person.x;cout<<"人y:";cin>>person.y;
	cout<<"箱子x:";cin>>box.x;cout<<"箱子y:";cin>>box.y;
	cout<<"目标x:";cin>>base.x;cout<<"目标y:";cin>>base.y;
	system("color F");
	fresh(person,box,base,map,x,y);
	while(true)
	{
		if(vkup.press(VK_UP)){up(person,preperson);if(person==box)press(person,preperson,box,prebox,area);fresh(person,box,base,map,x,y);}
		if(vkdown.press(VK_DOWN)){down(person,preperson,area);if(person==box)press(person,preperson,box,prebox,area);fresh(person,box,base,map,x,y);}
		if(vkleft.press(VK_LEFT)){left(person,preperson);if(person==box)press(person,preperson,box,prebox,area);fresh(person,box,base,map,x,y);}
		if(vkright.press(VK_RIGHT)){right(person,preperson,area);if(person==box)press(person,preperson,box,prebox,area);fresh(person,box,base,map,x,y);}
		if(box==base){system("color 0");system("color 1");system("color 2");system("color 3");system("color 4");system("color 5");system("color 6");system("color 7");system("color 8");system("color 9");system("color A");system("color B");system("color C");system("color D");system("color E");system("color F");}
		if(GetAsyncKeyState(VK_ESCAPE))return 0;
	}
	return 0;
}

