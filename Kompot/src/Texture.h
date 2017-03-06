#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <string>
#include <SDL\SDL.h>

class Texture
{
public:
	Texture();
	~Texture();

	//load an image from a specified class
	bool load(std::string path,SDL_Renderer* renderer);
	
	//render texture
	void render(int x, int y,int width,int height,SDL_Renderer* renderer);

	void destroy();

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

private:
	SDL_Texture* m_tex;

	//image dims
	int m_width;
	int m_height;

};

#endif
