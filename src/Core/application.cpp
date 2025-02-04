#include "application.h"

#include <iostream>

Application::Application()
{
	m_State = ApplicationState::SetupState;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(1920, 1080, "PokeEngine", NULL, NULL);
	if (m_Window == NULL)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		m_State = ApplicationState::NullState;
		
	}

	glfwSetWindowUserPointer(m_Window, this);
	glfwMakeContextCurrent(m_Window);

	glewInit();

	glClearColor(0, 0.7, 0.9, 1.0f);
	glViewport(0, 0, m_WIDTH, m_HEIGHT);

	glEnable(GL_DEPTH_TEST);
}

Application::~Application()
{
}

void Application::RunApplication()
{
	// Exits out of the application if null
	if (m_State == ApplicationState::NullState)
		return;

	m_State = ApplicationState::RunningState;

	while (m_State != ApplicationState::ShutdownState && !glfwWindowShouldClose(m_Window))
	{
		// Main loop code

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		glfwSwapBuffers(m_Window);
	}
}

void Application::SetScreenSize(unsigned int width, unsigned int height)
{
	m_WIDTH = width;
	m_HEIGHT = height;
}

void Application::GetScreenSize(unsigned int& outWidth, unsigned int& outHeight)
{
	outWidth = m_WIDTH;
	outHeight = m_HEIGHT;
}
