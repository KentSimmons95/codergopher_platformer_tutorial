#include "Entity.h"

#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float x, float y, SDL_Texture* texture)
	:x(x), y(y), tex(texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

void Entity::init()
{

}
