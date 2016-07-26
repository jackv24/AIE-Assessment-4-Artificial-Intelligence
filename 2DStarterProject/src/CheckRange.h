#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class CheckRange : public IBehaviour
{
public:
	CheckRange();
	CheckRange(Agent* target, float minDistance);
	virtual ~CheckRange();

	virtual Result Update(Agent *pAgent, float deltaTime);

private:
	Agent* m_target = nullptr;

	float m_minDistance = 0;
};

