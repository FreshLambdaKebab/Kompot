#include "Sprite.h"

Sprite::Sprite():
	m_texture(nullptr),
	m_position(0,0)
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

bool Sprite::Init(SDL_Renderer& renderer, const std::string& filePath,glm::vec2 position)
{
	//load the texture
	m_texture = IMG_LoadTexture(&renderer, filePath.c_str());
	if (m_texture == NULL) {
		return false;
	}

	//set the default position of the sprite
	m_position.x = position.x;
	m_position.y = position.y;

	//fill in the destination rect
	m_destRect.x = m_position.x;
	m_destRect.y = m_position.y;
	m_destRect.w = 100;
	m_destRect.h = 100;

	return true;
}

void Sprite::Draw(SDL_Renderer & renderer)
{
	SDL_RenderCopy(&renderer, m_texture, NULL, &m_destRect);
}
