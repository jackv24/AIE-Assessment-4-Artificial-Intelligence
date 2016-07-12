#pragma once

#include "Composite.h"

class Sequence : public Composite
{
public:
	Sequence();
	virtual ~Sequence();

	virtual Result Update(Agent *pAgent, float deltaTime);
};

