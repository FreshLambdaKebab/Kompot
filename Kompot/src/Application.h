#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <SDL\SDL.h>

class Application
{
public:
	Application();
	~Application();

	bool Init(int screenWidth,int screenHeight,const char* windowTitle);
	void Run();
	bool Update();
	void Draw();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	int m_screenWidth, m_screenHeight;
	bool m_done = false;
};

#endif
