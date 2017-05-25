#include "Graphics/Window.h"

Window::Window()
{
}

Window::Window(int width, int height, std::string title)
{
	this->Open(width, height, title);
}

Window::~Window()
{
}

void Window::Open(int width, int height, std::string title)
{
	Width = width;
	Height = height;
	Title = title;

	this->GlWindow = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
}

void Window::SetShouldClose(bool shouldClose)
{
	glfwSetWindowShouldClose(this->GlWindow, (GLboolean)shouldClose);
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(this->GlWindow);
}

bool Window::ShouldNotClose()
{
	return !glfwWindowShouldClose(this->GlWindow);
}

void Window::SetBackgroundColor(Color* color)
{
	BackgroundColor = color;
}

void Window::SetBackgroundColor(float r, float g, float b)
{
	BackgroundColor = new Color(r, g, b);
}

void Window::SetupViewport()
{
	glViewport(0, 0, Width, Height);
}

void Window::Clear()
{
	glClearColor(BackgroundColor->R, BackgroundColor->G, BackgroundColor->B, BackgroundColor->A);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(this->GlWindow);
}

GLFWwindow* Window::Context()
{
	return GlWindow;
}