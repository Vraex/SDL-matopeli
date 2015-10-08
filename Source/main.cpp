#include <SDL.h>
#include <stdio.h>
#include "Level.h"
#include "Window.h"
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <vector>

void LopetaPeli(Window);

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event e;
	SDL_Init( SDL_INIT_VIDEO );
	
	enum {UP, DOWN, LEFT, RIGHT};
	int suunta = DOWN;
	int old_suunta = suunta;

	Window ikkuna;

	int size = 20;
	int laskuri = 0;

	int start_x = 16, start_y = 12;
	int x = start_x, y = start_y;

	srand (time(NULL));

	int random_x = rand() % 31;
	int random_y = rand() % 23;
	
	//k‰‰rmeen kentt‰ x=31 , y=23

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
						if (old_suunta != DOWN)
						{
							suunta = UP;
						}
						
                    break;

                    case SDLK_DOWN:
						
						if (old_suunta != UP)
						{
							suunta = DOWN;
						}
						
                    break;

                    case SDLK_LEFT:

						if (old_suunta != RIGHT)
						{
							suunta = LEFT;
						}
                    break;

                    case SDLK_RIGHT:
						if (old_suunta != LEFT)
						{
							suunta = RIGHT;
						}
                    break;
                }
            }
		}
		
		laskuri++;

		if (laskuri > 15)
		{
			old_suunta = suunta;

			if (suunta == UP && snake[0].y-1>=0)
			{
				snake[0].y--;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == DOWN && snake[0].y+1<24)
			{
				snake[0].y++;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == LEFT && snake[0].x-1>=0)
			{
				snake[0].x--;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == RIGHT && snake[0].x+1<32)
			{
				snake[0].x++;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			laskuri = 0;
		}
	
		if (snake[0].x == random_x && snake[0].y == random_y)
		{
		random_x = rand() % 31;
		random_y = rand() % 23;
		}


		ikkuna.clear();
		
		

		for (int i = 0; i < snake_size; i++)
		{
			ikkuna.drawRect(snake[i].x * size, snake[i].y * size, 20, 20, 255, 0, 0);
		}


		ikkuna.drawRect(random_x * size, random_y * size, 20, 20, 0, 0, 255);
		ikkuna.refresh();

	}
	
	return 0;
}

void LopetaPeli(Window ikkuna)
{
		ikkuna.clear();
}