#include "Window.h"


Window::Window():
	m_screenWidth(0),
	m_screenHeight(0)
{
}

Window::~Window()
{
}

bool Window::CreateWindow(const std::string & title, const int & screenWidth, const int & screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	//create the window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (m_window == nullptr)
	{
		return false;
	}

	return true;
}

void Window::DestroyWindow()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
}
