#include "Sprite.h"
#include <iostream>

Sprite::Sprite():
	m_texture(nullptr),
	m_position(0, 0),
	m_size(0),
	m_destRect()
{
}

Sprite::~Sprite()
{
	//free the texture
	SDL_DestroyTexture(m_texture);
	m_texture = 0;

	//quit sdl image
	IMG_Quit();
}

bool Sprite::Init(SDL_Renderer& renderer, const std::string& filePath, glm::vec2 position, glm::vec2 size)
{
	//load the texture
	m_texture = IMG_LoadTexture(&renderer, filePath.c_str());
	if (m_texture == NULL) {
		std::cout << "could not load texture: " + filePath << std::endl;
		return false;
	}

	//set the default position of the sprite
	m_position.x = position.x;
	m_position.y = position.y;

	//set the initial size of the sprite
	m_size.x = size.x;
	m_size.y = size.y;

	//fill in the destination rect
	m_destRect.x = m_position.x;
	m_destRect.y = m_position.y;
	m_destRect.w = m_size.x;
	m_destRect.h = m_size.y;

	return true;
}

void Sprite::Draw(SDL_Renderer & renderer)
{
	SDL_RenderCopy(&renderer, m_texture, NULL, &m_destRect);
}

glm::vec2& Sprite::GetPosition()
{
	m_destRect.x = m_position.x;
	m_destRect.y = m_position.y;
	return m_position;
}

void Sprite::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	m_destRect.x = x;
	m_destRect.y = y;
}

