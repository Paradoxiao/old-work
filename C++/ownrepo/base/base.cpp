#include<iostream>
#include<windows.h>
using namespace std;
template<typename T>
struct listNode{T data;listNode* nextNode;listNode* lastNode;listNode(T& data){nextNode,lastNode=NULL;this->data=data;}};
template<class T>
class list
{
	private:
	long long number;long long now;
	public:
	listNode<T>* nowNode;
	list(void){nowNode=NULL;number,now=0;}
	~list(void){listNode<T>* temp;while(!nowNode){temp=nowNode->nextNode;delete nowNode;if(!temp)nowNode=temp;}}
	void add(T data)
	{
		listNode<T>* newNode=new listNode<T>(data);
		if(!nowNode)
		{
			nowNode=newNode;number=1;nowNode->nextNode=nowNode;nowNode->lastNode=nowNode;cout<<"当前节点总数:"<<number<<"  当前节点:1"<<endl;now=1;return;
		}
		listNode<T>* temp=nowNode->nextNode;
		nowNode->nextNode=newNode;newNode->lastNode=nowNode;
		newNode->nextNode=temp;temp->lastNode=newNode;
		nowNode=nowNode->nextNode;
		number++;now++;
		cout<<"当前节点总数:"<<number<<"  当前节点:"<<now<<endl;			
	}
	void next(void)
	{
		nowNode=nowNode->nextNode;if(now==number)now=1;else{now++;}
		cout<<"当前节点总数:"<<number<<"  当前节点:"<<now<<endl;
	}
	void last(void)
	{
		nowNode=nowNode->lastNode;if(now==1)now=number;else{now--;}
		cout<<"当前节点总数:"<<number<<"  当前节点:"<<now<<endl;
	}
	long long count(void)
	{
		return number;
	}
	void del(void)
	{
		if(number<=1)
		{
			cout<<"error"<<endl;
			return;
		}
		listNode<T>* temp=nowNode->lastNode;
		temp->nextNode=nowNode->nextNode;nowNode->nextNode->lastNode=temp;
		nowNode->nextNode,nowNode->lastNode=NULL;
		delete nowNode;
		nowNode=temp;
		number--;
		cout<<"当前节点总数:"<<number<<"  当前节点:"<<--now<<endl;		
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

