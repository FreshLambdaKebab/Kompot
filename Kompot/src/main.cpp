#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <stdio.h>
#include <string>

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
bool handleEvents();

SDL_Surface* loadSurface(std::string path)
{
	//the final optimized image
	SDL_Surface* optimizedSurface = nullptr;

	//load the image from the specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("unable to load image! %s SDL error: %s", path.c_str(), IMG_GetError());
	}
	else
	{
		//convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
		if (optimizedSurface == nullptr)
		{
			printf("unable to optimize image %s SDL error: %s", path.c_str(), SDL_GetError());
		}

		//get rid of the old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argc,char** argv)
{
	//loop flag
	bool quit = false;

	//initialize and create the window
	init();

	//load everything
	loadShit();

	while (!quit)
	{
		//update the application loop
		quit = handleEvents();

		//draw everything
		render();
	}

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

	//initialize PNG loading
	int imageFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imageFlags) & imageFlags))
	{
		printf("SDL image could not be initialized! SDL image error: %s\n", IMG_GetError());
		result = false;
	}
	else
	{
		//get the window surface
		screenSurface = SDL_GetWindowSurface(window);
	}

	return result;
}

void render()
{
	//fill the surface to a desired color
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));

	//apply the image
	SDL_BlitSurface(imageSurface, 0, screenSurface, 0);

	//update the surface
	SDL_UpdateWindowSurface(window);
}

bool loadShit()
{
	bool result = true;

	//load an image
	imageSurface = loadSurface("res/elysianshadows.png");
	if (imageSurface == NULL)
	{
		printf("could not load PNG image! \n");
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
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool handleEvents()
{
	SDL_Event windowEvent;
	bool quit = false;

	//handle all queue events
	while (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type)
		{
		case SDL_QUIT:
		{
			quit = true;
		}break;
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				quit = true;
			}
		}break;
		case SDL_KEYDOWN:
		{
			//exit the application when escape is pressed
			if (windowEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}break;
		}
	}

	return quit;
}
