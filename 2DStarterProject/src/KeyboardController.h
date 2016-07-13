#pragma once

#include "IBehaviour.h"
#include <GLFW\glfw3.h>

class KeyboardController : public IBehaviour
{
public:
	KeyboardController();
	virtual ~KeyboardController();

	virtual Result Update(Agent *pAgent, float deltaTime);

	void SetWindow(GLFWwindow* window);

private:
	GLFWwindow* m_window;
};

