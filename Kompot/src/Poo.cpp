#include "Poo.h"

Poo::Poo(SDL_Renderer& renderer,int x,int y) :
	Entity(renderer, "res/mrhankey.png", { x,y }, {100,100})
{
}

Poo::~Poo()
{
	
}

