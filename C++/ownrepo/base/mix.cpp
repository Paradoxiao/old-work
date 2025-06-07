#include<iostream>
#include<windows.h>
using namespace std;
template<typename T>
struct listNode{T data;listNode* nextNode;listNode* lastNode;listNode(T& data){nextNode,lastNode=NULL;this->data=data;}};
template<class T>
class list
{
	private:
	long long number;
	public:
	listNode<T>* nowNode;
	list(void){nowNode=NULL;number=0;}
	~list(void){listNode<T>* temp;while(!nowNode){temp=nowNode->nextNode;delete nowNode;if(!temp)nowNode=temp;}}
	void add(T data)
	{
		listNode<T>* newNode=new listNode<T>(data);
		if(!nowNode)
		{
			nowNode=newNode;number=1;nowNode->nextNode=nowNode;nowNode->lastNode=nowNode;return;
		}
		listNode<T>* temp=nowNode->nextNode;
		nowNode->nextNode=newNode;newNode->lastNode=nowNode;
		newNode->nextNode=temp;temp->lastNode=newNode;
		nowNode=nowNode->nextNode;
		number++;			
	}
	void next(void)
	{
		nowNode=nowNode->nextNode;
	}
	void last(void)
	{
		nowNode=nowNode->lastNode;
	}
	long long count(void)
	{
		return number;
	}
	void del(void)
	{
		if(number<=1)return;
		listNode<T>* temp=nowNode->lastNode;
		temp->nextNode=nowNode->nextNode;nowNode->nextNode->lastNode=temp;
		nowNode->nextNode,nowNode->lastNode=NULL;
		delete nowNode;nowNode=temp;
		number--;		
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

