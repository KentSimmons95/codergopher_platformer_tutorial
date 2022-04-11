#pragma once
#include <cstdio>
#include <SDl.h>
#include <SDL_image.h>

class RenderWindow
{
public:
	RenderWindow(const char* title, int w, int h);
	void cleanUp();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};