#pragma once
#include <cstdio>
#include <SDl.h>
#include <SDL_image.h>

#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* title, int w, int h);

	SDL_Texture* loadTexture(const char* file_path);
	void cleanUp();
	void clear();
	void render(Entity& entity);
	void display();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};