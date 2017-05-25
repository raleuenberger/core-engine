#pragma once

#include <string>

class Window;

class Engine
{
public:
	Engine();
	~Engine();

	void Start(int windowWidth, int windowHeight, std::string windowTitle);
	void Run();
	void Terminate();

private:
	Window* Pane;
};

