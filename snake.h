//snake

#include<windows.h>
#include<vector>

#define width 50
#define height 25

using namespace std;

class snake
{
	COORD pos;
	int len, vel;
	char direction;
	vector<COORD> body;
	
	public:
		
	snake(COORD pos, int vel)
	{
		this->pos = pos;
		this->vel = vel;
		len = 1;
		direction = 'n';
		
		body.push_back(pos);
	}
	
	void change_dir(char dir)
	{
		direction = dir;
	}
	
	void move_snake()
	{
		switch(direction)
		{
    		case 'u':
    		{
	    		pos.Y -= vel;
		    	break;
            }
			
    		case 'd':
	    	{
		    	pos.Y += vel;
    			break;
    		}
		
	    	case 'l':
		    {
			    pos.X -= vel;
    			break;
    		}
		
    		case 'r':
    		{
	    		pos.X += vel;
	    		break;
		    }
	    }
	    
	    body.push_back(pos);
	    
	    if(body.size() > len) body.erase(body.begin());
	}
	
	COORD get_pos()
	{
		return pos;
	}
	
	vector<COORD> getbody()
	{
		return body;
	}
	
	bool eaten(COORD food)
	{
		if(pos.X == food.X && pos.Y ==food.Y)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	void grow()
	{
		len++;
	}
	
	bool collided()
	{
		if(pos.X < 1 || pos.X > width-2 || pos.Y < 1 || pos.Y > height-2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
