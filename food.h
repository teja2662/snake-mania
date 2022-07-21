//food

#include<windows.h>
#include<cstdlib>

#define width 50
#define height 25

class food
{
	COORD pos;
	
	public:
	
	void gen_food()
	{
		pos.X = (rand() % width - 3) + 1;
		pos.Y = (rand() % height - 3) + 1;
	}
	
	COORD get_pos()
	{
		return pos;
	}
};