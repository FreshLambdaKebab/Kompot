#include "Framework.h"
#include <iostream>

Framework::Framework(int screenWidth, int screenHeight, const char * windowTitle):
	m_window(nullptr),
	m_renderer(nullptr),
	m_screenWidth(0),
	m_screenHeight(0)
{
	//initialize sdl2
	SDL_Init(SDL_INIT_EVERYTHING);

	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	//create the window
	m_window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (m_window == NULL) {
		std::cout << "the window could not be created.." << std::endl;
	}

	//create the sdl renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}


Framework::~Framework()
{
	//close and destroy the window
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

void Framework::BeginDraw()
{
	SDL_RenderClear(m_renderer);
}

void Framework::EndDraw()
{
	SDL_RenderPresent(m_renderer);
}

