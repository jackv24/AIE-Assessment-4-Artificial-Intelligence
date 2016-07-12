#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class Composite : public IBehaviour
{
public:
	Composite();
	virtual ~Composite();

	virtual Result Update(Agent *pAgent, float deltaTime) = 0;

	void AddChild(IBehaviour* behaviour);

protected:
	std::vector<IBehaviour*> m_childBehaviours;
	IBehaviour* m_pendingChild = nullptr;
};

