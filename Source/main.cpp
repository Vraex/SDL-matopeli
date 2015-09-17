#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	
	SDL_Window *window = NULL;

	SDL_Surface *screenSurface = NULL;

	SDL_Init( SDL_INIT_VIDEO );

	window = SDL_CreateWindow( "Matopeli", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	screenSurface = SDL_GetWindowSurface( window );

	//texture render?


	SDL_UpdateWindowSurface( window );

	SDL_Delay ( 5000 );

	SDL_Quit();

	return 0;
}