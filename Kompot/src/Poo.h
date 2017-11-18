#ifndef _POO_H
#define _POO_H

#include <SDL/SDL.h>
#include "Sprite.h"

class Poo
{
public:
	Poo();
	~Poo();

	void Draw(SDL_Renderer& renderer);

private:
	Sprite* m_pooSprite;

};

#endif
