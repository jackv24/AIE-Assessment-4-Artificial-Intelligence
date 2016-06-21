#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
}
KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(Agent *pAgent, float deltaTime)
{
	pAgent->AddForce(Vector2(10.0f, 10.0f) * deltaTime);
}