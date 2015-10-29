#include <SDL.h>
#include <stdio.h>
#include "Level.h"
#include "Window.h"
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

void GameOver(Window);

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event e;
	SDL_Init( SDL_INIT_VIDEO );
	
	enum {UP, DOWN, LEFT, RIGHT};
	int direction = DOWN;
	int old_direction = direction;

	Window window;

	int size = 20;
	int calculator = 0;

	int start_x = 16, start_y = 12;
	int x = start_x, y = start_y;

	srand (time(NULL));

	int random_x = rand() % 31;
	int random_y = rand() % 23;
	
	//k��rmeen kentt� x=31 , y=23

	Level square;
	
	int snake_size = 3;

	std::vector<SDL_Point> snake;

	SDL_Point tmp_point;

	for (int i = 0; i < snake_size; i++)
	{
		tmp_point.x = start_x;
		tmp_point.y = start_y + i;
		snake.push_back(tmp_point);
	}



	while (!quit) {

		while (SDL_PollEvent( &e ) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
						if (old_direction != DOWN)
						{
							direction = UP;
						}
						
                    break;

                    case SDLK_DOWN:
						
						if (old_direction != UP)
						{
							direction = DOWN;
						}
						
                    break;

                    case SDLK_LEFT:

						if (old_direction != RIGHT)
						{
							direction = LEFT;
						}
                    break;

                    case SDLK_RIGHT:
						if (old_direction != LEFT)
						{
							direction = RIGHT;
						}
                    break;
                }
            }
		}
		
		calculator++;
		
		//iterator?

		for (std::vector<SDL_Point>::iterator it = snake.begin() + 1; it != snake.end(); it++)
		{
			if ((snake.begin())->x == (*it).x &&
				(snake.begin())->y == (*it).y)
			{
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Game Over","You died!",NULL);
				SDL_Quit;
				return 0;
			}
		}

		
		if (calculator > 7)
		{
			old_direction = direction;
			int snake_x = snake[snake_size-1].x;
			int snake_y = snake[snake_size-1].y;

			if (direction == UP && snake_y-1>=0)
			{
				tmp_point.x = snake[snake_size-1].x;
				tmp_point.y = snake[snake_size-1].y - 1;
				//snake[0].y--;
				if (snake_x == random_x && snake_y == random_y)
				{
					snake_size++;
					random_x = rand() % 31;
					random_y = rand() % 23;
					snake.push_back(tmp_point);
				}
				else
				{
					snake.push_back(tmp_point);
					snake.erase(snake.begin());
				}
			
			}
			else if (direction == DOWN && snake_y+1<24)
			{
				//snake[0].y++;
				
				tmp_point.x = snake[snake_size-1].x;
				tmp_point.y = snake[snake_size-1].y + 1;

				if (snake_x == random_x && snake_y == random_y)
				{
					snake_size++;
					random_x = rand() % 31;
					random_y = rand() % 23;
					snake.push_back(tmp_point);
				}
				else
				{
					snake.push_back(tmp_point);
					snake.erase(snake.begin());
				}
			}
			else if (direction == LEFT && snake_x-1>=0)
			{
				//snake[0].x--;
				
				tmp_point.x = snake[snake_size-1].x - 1;
				tmp_point.y = snake[snake_size-1].y;

				if (snake_x == random_x && snake_y == random_y)
				{
					snake_size++;
					random_x = rand() % 31;
					random_y = rand() % 23;
					snake.push_back(tmp_point);
				}
				else
				{
					snake.push_back(tmp_point);
					snake.erase(snake.begin());
				}
			}
			else if (direction == RIGHT && snake_x+1<32)
			{
				//snake[0].x++;
				
				tmp_point.x = snake[snake_size-1].x + 1;
				tmp_point.y = snake[snake_size-1].y;

				if (snake_x == random_x && snake_y == random_y)
				{
					snake_size++;
					random_x = rand() % 31;
					random_y = rand() % 23;
					snake.push_back(tmp_point);
				}
				else
				{
					snake.push_back(tmp_point);
					snake.erase(snake.begin());
				}
			}
			else
			{
				//GameOver(window);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Game Over","You died!",NULL);
				SDL_Quit;
				return 0;
			}
			calculator = 0;
		}

		window.clear();
		
		for (int i = 0; i < snake_size; i++)
		{
			window.drawRect(snake[i].x * size, snake[i].y * size, 20, 20, 255, 0, 0);
		}

		window.drawRect(random_x * size, random_y * size, 20, 20, 0, 0, 255);
		window.refresh();
	}
	
	return 0;
}

void GameOver(Window window)
{
		window.clear();
}