#ifndef _PLAYER_H
#define _PLAYER_H

#include <SDL\SDL.h>
#include "Sprite.h"
#include "InputManager.h"

class Player
{
public:
	Player(SDL_Renderer& renderer);
	~Player();

	void Draw(SDL_Renderer& renderer);
	void Update(InputManager& input);

private:

	Sprite* m_sprite;

};

#endif
