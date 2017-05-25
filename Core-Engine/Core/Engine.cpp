#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core/Engine.h"
#include "Graphics/Window.h"

#include <iostream>

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Start(int windowWidth, int windowHeight, std::string windowTitle)
{
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	this->Pane = new Window(windowWidth, windowHeight, windowTitle);
	if (this->Pane == nullptr)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		this->Terminate();
		return;
	}

	glfwMakeContextCurrent(this->Pane->Context());

	//key callback funcs
	// here

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW." << std::endl;
		this->Terminate();
		return;
	}

	this->Pane->SetBackgroundColor(0.2f, 0.3f, 0.3f);
	this->Pane->SetupViewport();
	this->Run();
}

void Engine::Run()
{
	while (this->Pane->ShouldNotClose())
	{
		/* Input Here */
		//Input.PollEvents();

		/* Update State Here */

		this->Pane->Clear();

		/* Render Here */

		this->Pane->SwapBuffers();
	}
	
	this->Terminate();
}

void Engine::Terminate()
{
	glfwTerminate();
}