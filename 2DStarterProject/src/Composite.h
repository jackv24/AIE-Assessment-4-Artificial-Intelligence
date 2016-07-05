#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class Composite : public IBehaviour
{
public:
	Composite();
	~Composite();

	virtual void Update(Agent *pAgent, float deltaTime);

	std::list<IBehaviour*> childBehaviours;
};

