#include "Application.h"

int main(int argc,char** argv)
{
	Application app;
	app.Init(800, 600, "the fuckin title");
	app.Run();

	return 0;
}