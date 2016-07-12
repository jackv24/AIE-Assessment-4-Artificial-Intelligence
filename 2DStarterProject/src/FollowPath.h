#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class FollowPath : public IBehaviour
{
public:
	FollowPath();
	virtual ~FollowPath();

	virtual Result Update(Agent *pAgent, float deltaTime);

private:
	unsigned int m_index = 0;
};

