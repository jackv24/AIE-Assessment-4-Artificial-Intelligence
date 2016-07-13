#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
}
KeyboardController::~KeyboardController()
{
}

KeyboardController::Result KeyboardController::Update(Agent *pAgent, float deltaTime)
{
	Vector2 direction(0, 0);

	//Vertical input
	if (glfwGetKey(m_window, GLFW_KEY_W))
		direction = direction + Vector2(0, 1);
	else if (glfwGetKey(m_window, GLFW_KEY_S))
		direction = direction + Vector2(0, -1);

	//Horizontal input
	if (glfwGetKey(m_window, GLFW_KEY_A))
		direction = direction + Vector2(-1, 0);
	else if (glfwGetKey(m_window, GLFW_KEY_D))
		direction = direction + Vector2(1, 0);

	//Normalise direction (fixes faster diagonal movement)
	direction.normalise();

	pAgent->AddForce(direction * 200 * deltaTime);

	//Will always return success since it is a constant behaviour
	return Success;
}

void KeyboardController::SetWindow(GLFWwindow* window)
{
	m_window = window;
}
