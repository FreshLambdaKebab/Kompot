#ifndef _MAP_H
#define _MAP_H

#include "Entity.h"

class Map : public Entity
{
public:
	Map(SDL_Renderer& renderer,int width,int height);
	~Map();

private:

};

#endif
