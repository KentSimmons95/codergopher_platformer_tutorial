#include <cstdio>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"
#include "Entity.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		printf("Failed to initialise SDL_INIT_VIDEO, Error: %s", SDL_GetError());
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		printf("Failed to initialise IMG_Init, Error: %s", SDL_GetError());

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	//Floor entity
	std::vector<Entity> platform = {Entity(Vector2f(0, 150), grassTexture),
									Entity(Vector2f(30, 150), grassTexture),
									Entity(Vector2f(60, 150), grassTexture),
									Entity(Vector2f(90, 150), grassTexture),
									Entity(Vector2f(120, 150), grassTexture),
									Entity(Vector2f(150, 150), grassTexture),
									Entity(Vector2f(180, 150), grassTexture),
									Entity(Vector2f(210, 150), grassTexture),
									Entity(Vector2f(240, 150), grassTexture),
									Entity(Vector2f(270, 150), grassTexture),
									Entity(Vector2f(300, 150), grassTexture),
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
		
		//Render platforms
		for (Entity& e : platform)
		{
			window.render(e);
		}
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}