#define SDL_MAIN_HANDLED
#include <SDL3/SDL_main.h>
#include "Application.hpp"

int main() 
{
	Application app;

	app.update();
	app.draw();

	return 0;
}