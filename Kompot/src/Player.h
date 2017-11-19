#ifndef _PLAYER_H
#define _PLAYER_H

#include <SDL\SDL.h>
#include "Entity.h"
#include "InputManager.h"

class Player : public Entity
{
public:
	Player(SDL_Renderer& renderer);
	~Player();

	void Update(InputManager& input);

private:

};

#endif
