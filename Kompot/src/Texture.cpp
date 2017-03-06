#include "Texture.h"

#include <SDL\SDL_image.h>

Texture::Texture() :
	m_tex(nullptr),
	m_width(0),
	m_height(0)
{
}

Texture::~Texture()
{
	destroy();
}

bool Texture::load(std::string path,SDL_Renderer* renderer)
{
	//get rid of pre existing texture
	destroy();

	//final texture
	SDL_Texture* finalTex = nullptr;

	//load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("could not load surface! IMG Error: %s", IMG_GetError());
	}
	else
	{
		//color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));
		//create the texture from the surface pixels
		finalTex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (finalTex == NULL)
		{
			printf("unable to create texture from surface! SDL Error: %s", SDL_GetError());
		}

		//free old surface
		SDL_FreeSurface(loadedSurface);
	}

	m_tex = finalTex;
	return m_tex != NULL;
}

void Texture::render(int x, int y,int width,int height,SDL_Renderer *renderer)
{
	m_width = width;
	m_height = height;
	SDL_Rect destRect = { x,y,width,height };
	SDL_RenderCopy(renderer, m_tex, NULL, &destRect);
}

void Texture::destroy()
{
	//deallocate memory
	if (m_tex != nullptr)
	{
		SDL_DestroyTexture(m_tex);
		m_tex = nullptr;
		m_width = 0;
		m_height = 0;
	}
}
