#include "Application.h"
#include <iostream>

Application::Application():
	m_framework(nullptr)
{

}


Application::~Application()
{
	//delete the framework object
	delete m_framework;
	m_framework = 0;
}

bool Application::Init(int screenWidth, int screenHeight, const char * windowTitle)
{
	//initialize the framwork object
	m_framework = new Framework(screenWidth,screenHeight,windowTitle);
	if (!m_framework) {
		return false;
	}

	//initialize game shit here

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

	return true;
}

void Application::Draw()
{
	SDL_SetRenderDrawColor(m_framework->GetRenderer(), 255, 0, 0, 255);
	SDL_RenderClear(m_framework->GetRenderer());
	SDL_RenderPresent(m_framework->GetRenderer());
}
