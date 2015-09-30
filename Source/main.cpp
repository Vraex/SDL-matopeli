#include <SDL.h>
#include <stdio.h>
#include "Level.h"
#include "Window.h"

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

			if (suunta == UP && y-20>=0)
			{
				y -= 20;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == DOWN && y+20<Window_HEIGHT)
			{
				y += 20;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == LEFT && x-20>=0)
			{
				x -= 20;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			if (suunta == RIGHT && x+20<Window_WIDTH)
			{
				x += 20;
			}
			else
			{
				LopetaPeli(ikkuna);
			}
			laskuri = 0;
		}
	
		ikkuna.clear();
		ikkuna.drawRect(x, y, 20, 20, 255, 0, 0);
		ikkuna.refresh();
	}
	
	return 0;
}

void LopetaPeli(Window ikkuna)
{
		ikkuna.clear();
}