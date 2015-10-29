#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <SDL.h>

//game window size

const int Window_WIDTH = 640;
const int Window_HEIGHT = 480;

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