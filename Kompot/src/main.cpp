#include "Game.h"

int main(int argc,char** argv)
{
	Game game;
	game.Init(800, 600, "Pickup Shit");
	game.Run();

	return 0;
}