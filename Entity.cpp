#include "Entity.h"

#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Vector2f pos, SDL_Texture* texture)
	:pos(pos), tex(texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

void Entity::init()
{

}
