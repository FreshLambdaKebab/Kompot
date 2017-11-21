#include "Entity.h"
#include <iostream>

Entity::Entity(SDL_Renderer& renderer,const std::string& filepath, glm::vec2 position, glm::vec2 size)
{
	//create and initialize the sprite 
	m_sprite = new Sprite();
	m_sprite->Init(renderer, filepath, position, size);
}

Entity::~Entity()
{
	if (m_sprite) {
		delete m_sprite;
		m_sprite = 0;
	}
}

void Entity::Draw(SDL_Renderer& renderer)
{
	m_sprite->Draw(renderer);
}

