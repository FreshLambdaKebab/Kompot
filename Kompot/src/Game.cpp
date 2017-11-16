#include "Game.h"
#include <iostream>

Game::Game():
	m_framework(nullptr),
	m_sprite(nullptr),
	m_background(nullptr)
{

}

Game::~Game()
{
	//delete the framework object
	delete m_framework;
	m_framework = 0;

	//delete the sprite object
	delete m_sprite;
	m_sprite = 0;
	
	//delete background object
	delete m_background;
	m_background = 0;
}

bool Game::Init(int screenWidth, int screenHeight, const char * windowTitle)
{
	//initialize the framwork object
	m_framework = new Framework(screenWidth,screenHeight,windowTitle);
	if (!m_framework) {
		return false;
	}

	//initialize game shit here
	m_background = new Sprite();
	m_background->Init(*m_framework->GetRenderer(), "res/background.png", { 0,0 });

	m_sprite = new Sprite();
	m_sprite->Init(*m_framework->GetRenderer(), "res/foo.png", {200,200});

	return true;
}

void Game::Run()
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

bool Game::Update()
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

void Game::Draw()
{
	//render and set the background color
	SDL_SetRenderDrawColor(m_framework->GetRenderer(), 150, 50, 15, 255);
	m_framework->BeginDraw();

	//draw sprites
	m_background->Draw(*m_framework->GetRenderer());
	m_sprite->Draw(*m_framework->GetRenderer());

	//when finished drawing present rendered objects
	m_framework->EndDraw();
}