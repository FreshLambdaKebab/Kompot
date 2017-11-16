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

	bool Init(SDL_Renderer& renderer, const std::string& filePath,glm::vec2 position);
	void Draw(SDL_Renderer& renderer);

private:
	SDL_Texture* m_texture;
	glm::vec2 m_position;
	SDL_Rect m_destRect;
};

#endif
