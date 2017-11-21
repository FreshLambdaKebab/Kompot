#include "Player.h"

Player::Player(SDL_Renderer& renderer) :
	Entity(renderer, "res/stan.png", { 300,300 }, { 100,100 })
{

}

Player::~Player()
{

}

void Player::Update(InputManager& input)
{
	//move the player
	const float speed = 0.25f;
	if (input.IsKeyDown(SDLK_w))
		GetPosition().y -= speed;
	if (input.IsKeyDown(SDLK_a))
		GetPosition().x -= speed;
	if (input.IsKeyDown(SDLK_s))
		GetPosition().y += speed;
	if (input.IsKeyDown(SDLK_d))
		GetPosition().x += speed;

	//test bullshit
	if (input.IsKeyDown(SDLK_SPACE))
		SetPosition(400, 300);
}

