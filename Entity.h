#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(double x, double y, SDL_Texture* tex);
	void init();

private:
	double x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};