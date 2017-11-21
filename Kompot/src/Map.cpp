#include "Map.h"

Map::Map(SDL_Renderer& renderer, int width, int height) :
	Entity(renderer, "res/grass.png", { 0,0 }, { width,height })
{

}

Map::~Map()
{
}
