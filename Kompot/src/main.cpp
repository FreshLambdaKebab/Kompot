#include <SDL\SDL.h>
#include <stdio.h>

//screen dims
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();
bool loadShit();
void shutdown();

int main(int argc,char** argv)
{
	//create window pointer
	SDL_Window* window;

	//create the screen surface
	SDL_Surface* screenSurface = NULL;

	//initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//create window
	window = SDL_CreateWindow("The damn window title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	//get the window surface
	screenSurface = SDL_GetWindowSurface(window);

	//fill the surface to a desired color
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));

	//update the surface
	SDL_UpdateWindowSurface(window);

	//wait a few seconds
	SDL_Delay(3000);

	//destroy the window
	SDL_DestroyWindow(window);

	//quit sdl
	SDL_Quit();

	return 0;
}

bool init()
{
	return true;
}

bool loadShit()
{
	return true;
}

void shutdown()
{

}
