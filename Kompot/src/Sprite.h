#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <glm\glm.hpp>
#include <string>

class Sprite
{
public:
	Sprite();
	~Sprite();

	bool Init(SDL_Renderer& renderer, const std::string& filePath, glm::vec2 position, glm::vec2 size);
	void Draw(SDL_Renderer& renderer);

	//getters and setters
	const glm::vec2& GetPosition()const { return m_position; }
	glm::vec2& GetPosition();
	void SetPosition(float x, float y);

	SDL_Rect GetRect()const { return m_destRect; }

private:
	SDL_Texture* m_texture;
	glm::vec2 m_position;
	glm::vec2 m_size;
	SDL_Rect m_destRect;
};

#endif
