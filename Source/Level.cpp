#include "Level.h"

Level::Level()
{
	for (int i = 0; i < level_height; i++)
	{
		for (int j = 0; j < level_width; j++)
		{
			level[i][j] = 0;
		}
	}
}