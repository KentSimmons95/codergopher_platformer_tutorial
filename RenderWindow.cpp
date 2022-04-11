#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* title, int w, int h)
	:window(NULL), renderer(NULL)
{
	//Create our window
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		printf("Failed to init Window, Error: %s", SDL_GetError());

	//Create our renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* file_path)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, file_path);

	if (texture == NULL)
		printf("Failed to LoadTexture, Error: %s", SDL_GetError());
	
	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* tex)
{
	SDL_RenderCopy(renderer, tex, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
