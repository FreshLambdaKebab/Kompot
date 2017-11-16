#ifndef _Game_H
#define _Game_H

#include "Framework.h"

#include "Sprite.h"

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
	Framework* m_framework;
	bool m_done = false;

	//declare game shit here
	Sprite* m_sprite;
	Sprite* m_background;
};

#endif
