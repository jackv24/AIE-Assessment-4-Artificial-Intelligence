#pragma once

#include "Composite.h"

class Selector : public Composite
{
public:
	Selector();
	virtual ~Selector();

	virtual Result Update(Agent *pAgent, float deltaTime);
};

