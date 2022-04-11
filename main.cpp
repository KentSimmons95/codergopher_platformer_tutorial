#include <cstdio>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"
#include "Entity.h"

using namespace std;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		printf("Failed to initialise SDL_INIT_VIDEO, Error: %s", SDL_GetError());
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		printf("Failed to initialise IMG_Init, Error: %s", SDL_GetError());

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	//Floor entity
	vector<Entity> floor = {	Entity(0, 150, grassTexture),
								Entity(30, 150, grassTexture),
								Entity(60, 150, grassTexture),
								Entity(90, 150, grassTexture),
								Entity(120, 150, grassTexture),
								Entity(150, 150, grassTexture),
								Entity(180, 150, grassTexture),
								Entity(210, 150, grassTexture),
								Entity(240, 150, grassTexture),
								Entity(270, 150, grassTexture),
								Entity(300, 150, grassTexture),
	};
	

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

		window.clear();
		
		for (int i = 0; i < floor.size(); ++i)
		{
			window.render(floor[i]);
		}
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}