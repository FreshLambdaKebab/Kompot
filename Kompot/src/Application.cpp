#include "Application.h"
#include <iostream>

Application::Application():
	m_window(nullptr),
	m_renderer(nullptr),
	m_screenWidth(0),
	m_screenHeight(0)
{
	
}


Application::~Application()
{
	//close and destroy the window
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

bool Application::Init(int screenWidth, int screenHeight, const char * windowTitle)
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
		return false;
	}

	//create the sdl renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	return true;
}

void Application::Run()
{
	//mane gaim loop
	while (!m_done)
	{
		//update logic...
		Update();

		//render shit...
		Draw();
	}

}

bool Application::Update()
{
	SDL_Event windowEvent;

	//handle events
	while (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type)
		{
		case SDL_QUIT:
			m_done = true;
			return false;
			break;
		}

		//if the user pressed escape, exit out the window
		if (windowEvent.key.keysym.sym == SDLK_ESCAPE)
		{
			m_done = true;
			return false;
		}
	}
	std::cout << "updating shit\n";
	return true;
}

void Application::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
	std::cout << "rendering shit\n";
}
