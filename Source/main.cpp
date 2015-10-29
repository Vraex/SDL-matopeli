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

#define LEVEL_WIDTH 31
#define LEVEL_HEIGHT 23

bool doesCollect(SDL_Point snake, SDL_Point collectable) {
	if (snake.x == collectable.x && snake.y == collectable.y)
	{
		return true;
	}

	return false;
}

SDL_Point newCollectable(std::vector<SDL_Point> snake) {
	SDL_Point collectable;
	bool inside_snake = false;

	do {
		collectable.x = rand() % LEVEL_WIDTH;
		collectable.y = rand() % LEVEL_HEIGHT;
		inside_snake = false;

		for (std::vector<SDL_Point>::iterator it = snake.begin(); it != snake.end(); it++)
		{
			if (collectable.x == (*it).x &&
				collectable.y == (*it).y)
				{
					inside_snake = true;
				}
		}
	} while(inside_snake);

	return collectable;
}

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

	//int *size_ptr = &size;

	int start_x = 16, start_y = 12;
	int x = start_x, y = start_y;

	srand (time(NULL));

	std::vector<SDL_Point> snake;
	SDL_Point collectable = newCollectable(snake);
	//int random_x = rand() % 31;
	//int random_y = rand() % 23;
	
	//Size of the map x=31 , y=23

	int snake_size = 3;

	//Starting snake
	SDL_Point tmp_point;
	for (int i = 0; i < snake_size; i++)
	{
		tmp_point.x = start_x;
		tmp_point.y = start_y + i;
		snake.push_back(tmp_point);
	}

	//Main loop
	while (!quit) {

		while (SDL_PollEvent( &e ) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN )
            {
                //Game controls
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
		
		//snake hitting itself

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

		//Snake speed
		if (calculator > 8)
		{
			old_direction = direction;
			int snake_x = snake.back().x;
			int snake_y = snake[snake_size-1].y;

			if (direction == UP && snake_y-1>=0)
			{
				tmp_point.x = snake[snake_size-1].x;
				tmp_point.y = snake[snake_size-1].y - 1;
				snake.push_back(tmp_point);

				//Hitting a collectable
				if (doesCollect(snake.back(), collectable))
				{
					snake_size++;
					collectable = newCollectable(snake);
				} else {
					snake.erase(snake.begin());
				}
			}
			else if (direction == DOWN && snake_y+1<24)
			{
				tmp_point.x = snake[snake_size-1].x;
				tmp_point.y = snake[snake_size-1].y + 1;
				snake.push_back(tmp_point);

				//Hitting a collectable
				if (doesCollect(snake.back(), collectable))
				{
					snake_size++;
					collectable = newCollectable(snake);
				} else {
					snake.erase(snake.begin());
				}
			}

			else if (direction == LEFT && snake_x-1>=0)
			{
				tmp_point.x = snake.back().x - 1;
				tmp_point.y = snake[snake_size-1].y;
				snake.push_back(tmp_point);

				//Hitting a collectable
				if (doesCollect(snake.back(), collectable))
				{
					snake_size++;
					collectable = newCollectable(snake);
				} else {
					snake.erase(snake.begin());
				}
			}

			else if (direction == RIGHT && snake_x < LEVEL_WIDTH)
			{
				tmp_point.x = snake[snake_size-1].x + 1;
				tmp_point.y = snake[snake_size-1].y;
				snake.push_back(tmp_point);

				//Hitting a collectable
				if (doesCollect(snake.back(), collectable))
				{
					snake_size++;
					collectable = newCollectable(snake);
				} else {
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
		
		//Drawing the snake

		for (int i = 0; i < snake_size; i++)
		{
			window.drawRect(snake[i].x * size, snake[i].y * size, 20, 20, 255, 0, 0);
		}

		window.drawRect(collectable.x * size, collectable.y * size, 20, 20, 0, 0, 255);
		window.refresh();
	}
	
	return 0;
}

void GameOver(Window window)
{
		window.clear();
}