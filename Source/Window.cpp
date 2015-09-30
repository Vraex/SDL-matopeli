#include "Window.h"

Window::Window()
{
	window = SDL_CreateWindow("Matopeli", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_WIDTH, Window_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::refresh()
{
	SDL_RenderPresent(renderer);
}

void Window::fill(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		
	SDL_RenderClear(renderer);
}

void Window::clear()
{
	fill(0,0,0);
}

void Window::drawRect(int x, int y, int w, int h, int r, int g, int b)
{
	SDL_Rect fillRect = {x, y, w, h};
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &fillRect );
}

