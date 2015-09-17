#ifndef GAMECONTROL_H_DEFINED
#define GAMECONTROL_H_DEFINED

#include <SDL.h>
#include <stdio.h>
#include <string>

class GameControl
{
public:
	GameControl();
	
	std::string GameArea [4][4];
};

#endif