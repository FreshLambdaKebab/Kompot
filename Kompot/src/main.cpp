#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <stdio.h>
#include <string>

#include "Texture.h"

//screen dims
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//create window pointer
SDL_Window* window = NULL;
SDL_Renderer* renderer = nullptr;

//surfaces
SDL_Surface* screenSurface = NULL;
SDL_Surface* imageSurface = NULL;

//textures
SDL_Texture* texture = nullptr;

//scene textures
Texture fooTex;
Texture backgroundTex;

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
SDL_Texture* loadTexture(std::string path)
{
	//final texture
	SDL_Texture* tex = nullptr;

	//load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("could not load surface! IMG Error: %s", IMG_GetError());
	}
	else
	{
		//create the texture from the surface pixels
		tex = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (tex == NULL)
		{
			printf("unable to create texture from surface! SDL Error: %s",SDL_GetError());
		}

		//free old surface
		SDL_FreeSurface(loadedSurface);
	}
	return tex;
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
	else
	{
		//create the renderer for the window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			printf("could not create renderer!! SDL Error: %s", SDL_GetError());
			result = false;
		}
		else
		{
			//if the renderer was succesfully created
			//initialize the renderer color
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			//initialize PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				printf("SDL image could not be initialized! SDL image error: %s\n", IMG_GetError());
				result = false;
			}
		}
	}

	return result;
}

void render()
{
	//clear the screen to desired color
	SDL_SetRenderDrawColor(renderer, 255, 255, 105, 255);
	SDL_RenderClear(renderer);


	//create viewport
	SDL_Rect viewPort;
	viewPort.x = 0;
	viewPort.y = 0;
	viewPort.w = SCREEN_WIDTH;
	viewPort.h = SCREEN_HEIGHT;
	SDL_RenderSetViewport(renderer, &viewPort);

	//render textures to the screen
	backgroundTex.render(0, 0,SCREEN_WIDTH,SCREEN_HEIGHT, renderer);
	fooTex.render(400, 300,100,100 ,renderer);

	//render a filled quad
	//SDL_Rect quadRect = { SCREEN_WIDTH / 4,SCREEN_HEIGHT / 4,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &quadRect);

	//update screen
	SDL_RenderPresent(renderer);
}

bool loadShit()
{
	bool result = true;

	//load dude texture
	if (!fooTex.load("res/foo.png", renderer))
	{
		printf("failed to load foo image\n");
		result = false;
	}

	//load background texture
	if (!backgroundTex.load("res/background.png", renderer))
	{
		printf("failed to load background image\n");
		result = false;
	}

	return result;
}

void shutdown()
{
	//free loaded images
	fooTex.destroy();
	backgroundTex.destroy();

	//free loaded image
	//SDL_DestroyTexture(texture);
	//texture = nullptr;

	//destroy the window & renderer
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

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
