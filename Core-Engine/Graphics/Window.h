#pragma once
#include <GLFW/glfw3.h>

#include "Graphics/Color.h"

#include <string>

class Window
{
public:
	Window();
	Window(int width, int height, std::string title);
	~Window();

	void Open(int width, int height, std::string title);

	void SetShouldClose(bool shouldClose);
	bool ShouldClose();
	bool ShouldNotClose();

	void SetBackgroundColor(Color* color);
	void SetBackgroundColor(float r, float g, float b);

	void SetupViewport();

	void Clear();
	void SwapBuffers();

	GLFWwindow* Context();

private:
	Color* BackgroundColor;
	GLuint Width;
	GLuint Height;
	std::string Title;
	GLFWwindow* GlWindow;
};

