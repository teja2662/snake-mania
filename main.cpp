//board

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<ctime>

#include "snake.h"
#include "food.h"

#define width 50
#define height 25

using namespace std;

snake snake({width/2, height/2}, 1);
food obj;

int score=0;

void board()
{
	COORD snake_pos=snake.get_pos();
	COORD food_pos = obj.get_pos();
	
	vector<COORD> snakebody = snake.getbody(); 
	
	cout<<"SCORE : "<<score<<endl<<endl;
	
	for(int i=0; i<height; i++)
	{
		cout<<"\t\t#";
		
		for(int j=0; j<width-2; j++)
		{
			if(i==0 || i==height-1)
			{
				cout<<"#";
			}
			else if(i==snake_pos.Y && j+1 ==snake_pos.X)
			{
				cout<<'O';
			}
			else if(i == food_pos.Y && j+1 == food_pos.X)
			{
				cout<<'$';
			}
			else
			{
				bool isbodypart = false;
				for(int k=0; k<snakebody.size()-1; k++)
				{
					if(i==snakebody[k].Y && j+1 == snakebody[k].X)
					{
						cout<<'o';
						isbodypart = true;
						break;
					}
				}
				
				if(!isbodypart)
				{
					cout<<' ';
				}
			}
		}
		cout<<"#\n";
	}
}

int main()
{
	score=0;
	srand(time(NULL));
	
	obj.gen_food();
	
	bool game_over = false;
	
	while(!game_over)
	{
		board();
		
		if(kbhit())
		{
			switch(getch())
			{
				case 'w':
				{
					snake.change_dir('u');
					break;
				}
				
				case 'd':
				{
					snake.change_dir('r');
					break;
				}
				
				case 's':
				{
					snake.change_dir('d');
					break;
				}
				
				case 'a':
				{
					snake.change_dir('l');
					break;
				}
			}
		}
		
		if(snake.eaten(obj.get_pos()))
		{
			obj.gen_food();
			snake.grow();
			score++;
		}
		
		if(snake.collided())
		{
			game_over = true;
		}
		
		snake.move_snake();
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	}
}
