#pragma once
#include <cstdio>
#include <SDl.h>
#include <SDL_image.h>

class RenderWindow
{
public:
	RenderWindow(const char* title, int w, int h);

	SDL_Texture* loadTexture(const char* file_path);
	void cleanUp();
	void clear();
	void render(SDL_Texture* tex);
	void display();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};