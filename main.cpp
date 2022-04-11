#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		printf("Failed to initialise SDL_INIT_VIDEO, Error: %s", SDL_GetError());
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		printf("Failed to initialise IMG_Init, Error: %s", SDL_GetError());

	RenderWindow window("GAME v1.0", 1280, 720);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}