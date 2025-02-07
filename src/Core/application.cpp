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
		std::cerr << "Failed to create window!" << std::endl;
		glfwTerminate();
		m_State = ApplicationState::NullState;
		return;
	}

	glfwSetWindowUserPointer(m_Window, this);
	glfwMakeContextCurrent(m_Window);

	glewInit();

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW!" << std::endl;
		glfwTerminate();
		m_State = ApplicationState::NullState;
		return;
	}

	glClearColor(0, 0.7, 0.9, 1.0f);
	glViewport(0, 0, m_WIDTH, m_HEIGHT);

	glEnable(GL_DEPTH_TEST);

	// GLFW Callbacks

	glfwSetWindowSizeCallback(m_Window, ResizeWindowCallback);

}

Application::~Application()
{
	if (m_Window)
	{
		glfwDestroyWindow(m_Window);
		m_Window = nullptr;
	}
	glfwTerminate();
}

void Application::RunApplication()
{
	// Exits out of the application if null
	if (m_State == ApplicationState::NullState)
		return;

	m_State = ApplicationState::RunningState;

	float lastFrameTime = 0.0f;

	while (m_State != ApplicationState::ShutdownState && !glfwWindowShouldClose(m_Window))
	{
		// Main loop code

		// Calculate delta time

		float currentFrameTime = static_cast<float>(glfwGetTime());
		float deltaTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		// OpenGL and GLFW stuff

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		glfwSwapBuffers(m_Window);
	}
}

void Application::SetScreenSize(unsigned int width, unsigned int height)
{
	if (!m_Window) return;

	m_WIDTH = width;
	m_HEIGHT = height;

	glfwSetWindowSize(m_Window, m_WIDTH, m_HEIGHT);
	glViewport(0, 0, m_WIDTH, m_HEIGHT);
}

void Application::GetScreenSize(unsigned int& outWidth, unsigned int& outHeight) const
{
	outWidth = m_WIDTH;
	outHeight = m_HEIGHT;
}

void ResizeWindowCallback(GLFWwindow* window, int width, int height)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	app->SetScreenSize(width, height);
}
