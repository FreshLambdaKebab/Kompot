#include "Poo.h"

Poo::Poo(SDL_Renderer& renderer)
{
	m_pooSprite = new Sprite();
	m_pooSprite->Init();
}

Poo::~Poo()
{
}
