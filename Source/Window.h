#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <SDL.h>

class Window
{
public:
	
	SDL_Window *window;
	SDL_Renderer *renderer;
	void refresh();
	void fill(int r, int g, int b);
	void clear();
	Window();
	void drawRect(int x, int y, int w, int h, int r, int g, int b);

private:
};

#endif