#include <SDL.h>
#include <stdio.h>
#include "Level.h"
#include "Window.h"
#include <cstdlib>
#include <time.h>

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
	int x = 16;
	int y = 12;

	srand (time(NULL));

	int random_x = rand() % 31;
	int random_y = rand() % 23;
	
	//käärmeen kenttä x=31 , y=23

	Level square;


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

			if (suunta == UP && y-1>=0)
			{
				y -= 1;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == DOWN && y+1<24)
			{
				y += 1;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == LEFT && x-1>=0)
			{
				x -= 1;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == RIGHT && x+1<32)
			{
				x += 1;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			laskuri = 0;
		}
	
		if (x == random_x && y == random_y)
		{
		random_x = rand() % 31;
		random_y = rand() % 23;
		}

		ikkuna.clear();
		ikkuna.drawRect(x * size, y * size, 20, 20, 255, 0, 0);
		ikkuna.drawRect(random_x * size, random_y * size, 20, 20, 0, 0, 255);
		ikkuna.refresh();

	}
	
	return 0;
}

void LopetaPeli(Window ikkuna)
{
		ikkuna.clear();
}