#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Framework.h"

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
	Framework* m_framework;
	bool m_done = false;


};

#endif
