#pragma once

#include "IBehaviour.h"

class KeyboardController : public IBehaviour
{
public:
	KeyboardController();
	~KeyboardController();

	virtual void Update(Agent *pAgent, float deltaTime);
};

