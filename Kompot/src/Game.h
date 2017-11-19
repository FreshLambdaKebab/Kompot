#ifndef _Game_H
#define _Game_H

#include "Framework.h"

#include "InputManager.h"

#include "Player.h"
#include "Poo.h"
#include "Map.h"

class Game
{
public:
	Game();
	~Game();

	bool Init(int screenWidth,int screenHeight,const char* windowTitle);
	void Run();
	bool Update();
	void Draw();


private:
	void HandleInput();
	void HandleCollision();

	Framework* m_framework;
	bool m_done = false;

	//declare game shit here
	Player* m_player;
	Map* m_map;
	InputManager m_inputManager;
	Poo* m_poo;
	
};

#endif
