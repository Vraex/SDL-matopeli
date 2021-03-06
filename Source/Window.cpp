#include "Window.h"

//Creating game window

Window::Window()
{
	window = SDL_CreateWindow("Matopeli", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_WIDTH, Window_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::refresh()
{
	SDL_RenderPresent(renderer);
}

//Background color

void Window::fill(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, 75, b, 255);
		
	SDL_RenderClear(renderer);
}

void Window::clear()
{
	fill(0,0,0);
}

//Drawing the snake

void Window::drawRect(int x, int y, int w, int h, int r, int g, int b)
{
	SDL_Rect fillRect = {x, y, w, h};
	SDL_SetRenderDrawColor(renderer, r, 200, b, 255);
	SDL_RenderFillRect(renderer, &fillRect );
}

