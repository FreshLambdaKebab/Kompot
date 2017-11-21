#ifndef _POO_H
#define _POO_H

#include <SDL/SDL.h>
#include <glm\glm.hpp>
#include "Entity.h"

class Poo : public Entity
{
public:
	Poo(SDL_Renderer& renderer,int x,int y);
	~Poo();

private:
	glm::vec2 m_position;

};

#endif
