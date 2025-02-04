#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum ApplicationState {
	NullState,
	SetupState,
	RunningState,
	ShutdownState
};

class Application {

public:

	// Constructor
	// Sets up the application
	Application();

	// Destructor
	~Application();

	// Runs the main loop
	void RunApplication();

	//@@@@@@@@/
	
	// Sets the screen size
	void SetScreenSize(unsigned int width, unsigned int height);

	// Gets the screen size
	void GetScreenSize(unsigned int& outWidth, unsigned int& outHeight);

	ApplicationState GetApplicationState() const { return m_State; } 

private:

	GLFWwindow* m_Window = nullptr;

	unsigned int m_WIDTH = 1920;
	unsigned int m_HEIGHT = 1080;

	ApplicationState m_State = NullState;

};
