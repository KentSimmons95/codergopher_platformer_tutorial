#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Math.h"

class Entity
{
public:
	Entity(Vector2f pos, SDL_Texture* texture);
	void init();
	Vector2f& getPos() { return pos; };
	SDL_Texture* getTex() { return tex; };
	SDL_Rect getCurrentFrame() { return currentFrame; };

private:
	Vector2f pos;

	SDL_Rect currentFrame;
	SDL_Texture* tex;
};