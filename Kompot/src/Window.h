#pragma once

#include <SDL\SDL.h>
#include <string>

class Window
{
public:
	Window();
	~Window();

	bool CreateWindow(const std::string& title, const int& screenWidth, const int& screenHeight);
	void DestroyWindow();

	SDL_Window* GetWindow()const { return m_window; }

private:
	int m_screenWidth;
	int m_screenHeight;

	SDL_Window* m_window;

};

