#include <SDL\SDL.h>
#include <stdio.h>

//screen dims
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//create window pointer
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* imageSurface = NULL;

bool init();
void render();
bool loadShit();
void shutdown();

int main(int argc,char** argv)
{
	//initialize and create the window
	init();

	//load everything
	loadShit();

	//draw everything
	render();

	//wait a few seconds
	SDL_Delay(7000);

	//shutdown and free memory
	shutdown();

	return 0;
}

bool init()
{
	//initialization flag
	bool result = true;

	//initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		result = false;
	}

	//create window
	window = SDL_CreateWindow("The damn window title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		result = false;
	}

	//get the window surface
	screenSurface = SDL_GetWindowSurface(window);

	return result;
}

void render()
{
	//fill the surface to a desired color
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));

	//apply the image
	SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);

	//update the surface
	SDL_UpdateWindowSurface(window);
}

bool loadShit()
{
	bool result = true;

	//load an image
	imageSurface = SDL_LoadBMP("res/hello_world.bmp");
	if (imageSurface == NULL)
	{
		printf("could not load the image! SDL Error: %s\n",SDL_GetError());
		result = false;
	}

	return result;
}

void shutdown()
{
	//deallocate memory
	SDL_FreeSurface(imageSurface);
	imageSurface = NULL;

	//destroy the window
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}
