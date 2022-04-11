#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float x, float y, SDL_Texture* texture);
	void init();

	float getX() { return x; };
	float getY() { return y; };
	SDL_Texture* getTex() { return tex; };
	SDL_Rect getCurrentFrame() { return currentFrame; };

private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};