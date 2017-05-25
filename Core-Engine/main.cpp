#include "Engine.h"

int main()
{
	Engine* Game = new Engine();
	Game->Start(600, 400, "Core Engine");
	return 0;
}