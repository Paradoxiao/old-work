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
