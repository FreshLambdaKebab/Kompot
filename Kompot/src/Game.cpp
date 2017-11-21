#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game():
	m_framework(nullptr),
	m_player(nullptr),
	m_map(nullptr)
{

}

Game::~Game()
{
	//delete the framework object
	delete m_framework;
	m_framework = 0;

	//delete the sprite object
	delete m_player;
	m_player = 0;
	
	//delete map object
	delete m_map;
	m_map = 0;

	//delete and clear all the poos
	for (std::vector<Poo*>::iterator it = m_poos.begin(); it != m_poos.end(); ++it) {
		delete *it;
	}
	m_poos.clear();
}

bool Game::Init(int screenWidth, int screenHeight, const char * windowTitle)
{
	//initialize the framwork object
	m_framework = new Framework(screenWidth,screenHeight,windowTitle);
	if (!m_framework) {
		return false;
	}

	//initialize game shit here
	m_map = new Map(*m_framework->GetRenderer(), screenWidth, screenHeight);

	//create the player
	m_player = new Player(*m_framework->GetRenderer());

	//create the poo
	m_poos.push_back(new Poo(*m_framework->GetRenderer(), 400, 300));
	m_poos.push_back(new Poo(*m_framework->GetRenderer(), 500, 200));
	m_poos.push_back(new Poo(*m_framework->GetRenderer(), 100, 250));

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
		case SDL_MOUSEMOTION:
			m_inputManager.SetMouseCoords(static_cast<float>(windowEvent.motion.x), static_cast<float>(windowEvent.motion.y));
			break;
		case SDL_KEYDOWN:
			m_inputManager.PressKey(windowEvent.key.keysym.sym);

			//if the user pressed escape, exit out the window
			if (windowEvent.key.keysym.sym == SDLK_ESCAPE) {
				m_done = true;
				return false;
			}
			break;
		case SDL_KEYUP:
			m_inputManager.ReleaseKey(windowEvent.key.keysym.sym);
			break;
		}		

	}

	//update player
	m_player->Update(m_inputManager);

	//handle user input & collision
	HandleInput();
	HandleCollision();

	return true;
}

void Game::Draw()
{
	m_framework->BeginDraw();

	//draw sprites
	m_map->Draw(*m_framework->GetRenderer());
	m_player->Draw(*m_framework->GetRenderer());

	//draw all the poos (if the poos are not eaten)
	if(!pooEaten)
		for (std::vector<Poo*>::iterator it = m_poos.begin(); it != m_poos.end(); ++it) {
			(*it)->Draw(*m_framework->GetRenderer());
		}

	//when finished drawing present rendered objects
	m_framework->EndDraw();
}

void Game::HandleInput()
{
	
}

void Game::HandleCollision()
{

	for (std::vector<Poo*>::iterator it = m_poos.begin(); it != m_poos.end(); ++it)
	{
		//check if the player rect hits the poo rect
		if ((m_player->GetSprite()->GetRect().x == (*it)->GetRect().x) && (m_player->GetSprite()->GetRect().y == (*it)->GetRect().y)) {
			std::cout << "stan ate shit" << std::endl;
			pooEaten = true;
		}
	}
}
