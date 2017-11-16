#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#include <SDL\SDL.h>

class Framework
{
public:
	Framework(int screenWidth, int screenHeight, const char * windowTitle);
	~Framework();

	void BeginDraw();
	void EndDraw();

	//getters for sdl pointers
	SDL_Window* GetWindow()const { return m_window; }
	SDL_Renderer* GetRenderer()const { return m_renderer; }

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	int m_screenWidth, m_screenHeight;

};

#endif
