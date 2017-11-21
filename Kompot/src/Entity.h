#ifndef _ENTITY_H
#define _ENTITY_H

#include "Sprite.h"

class Entity
{
public:
	Entity(SDL_Renderer& renderer,const std::string& filepath,glm::vec2 position,glm::vec2 size);
	virtual ~Entity();

	virtual void Draw(SDL_Renderer& renderer);

	Sprite* GetSprite() { return m_sprite; }

	//getters and setters
	const glm::vec2& GetPosition()const { return m_sprite->GetPosition(); }
	glm::vec2& GetPosition() { return m_sprite->GetPosition(); }
	void SetPosition(float x, float y) { return m_sprite->SetPosition(x, y); }

	SDL_Rect GetRect()const { return m_sprite->GetRect(); }

private:
	Sprite* m_sprite;//every entity has a sprite
	
};

#endif
