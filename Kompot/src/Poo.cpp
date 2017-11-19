#include "Poo.h"

Poo::Poo(SDL_Renderer& renderer) :
	Entity()
{
	Init(renderer, "res/mrhankey.png", { 400,300 }, {100,100});
}

Poo::~Poo()
{
	
}

