#include <SDL.h>
#include <stdio.h>
#include "Level.h"
#include "Window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event e;
	SDL_Init( SDL_INIT_VIDEO );
	
	enum {UP, DOWN, LEFT, RIGHT};
	int suunta = DOWN;
	int old_suunta = suunta;

	Window ikkuna;

	int laskuri = 0;
	int x = 100;
	int y = 100;

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

		if (laskuri > 30)
		{
			old_suunta = suunta;

			if (suunta == UP)
			{
				y -= 30;
			}
			else if (suunta == DOWN)
			{
				y += 30;
			}
			else if (suunta == LEFT)
			{
				x -= 30;
			}
			else if (suunta == RIGHT)
			{
				x += 30;
			}
			laskuri = 0;
		}


		ikkuna.clear();
		ikkuna.drawRect(x, y, 30, 30, 255, 0, 0);
		ikkuna.refresh();
	}

	
	return 0;
}