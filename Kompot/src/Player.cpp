#include "Player.h"

Player::Player(SDL_Renderer& renderer) :
	m_sprite(nullptr)
{
	m_sprite = new Sprite();
	m_sprite->Init(renderer, "res/stan.png", { 300,300 }, {100,100});
}

Player::~Player()
{
	if (m_sprite) {
		delete m_sprite;
		m_sprite = 0;
	}
}

void Player::Draw(SDL_Renderer& renderer)
{
	m_sprite->Draw(renderer);
}

void Player::Update(InputManager& input)
{
	//move the player
	const float speed = 0.25f;
	if (input.IsKeyDown(SDLK_w))
		m_sprite->GetPosition().y -= speed;
	if (input.IsKeyDown(SDLK_a))
		m_sprite->GetPosition().x -= speed;
	if (input.IsKeyDown(SDLK_s))
		m_sprite->GetPosition().y += speed;
	if (input.IsKeyDown(SDLK_d))
		m_sprite->GetPosition().x += speed;
}

