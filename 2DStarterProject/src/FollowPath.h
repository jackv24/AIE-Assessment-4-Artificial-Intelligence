#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class FollowPath : public IBehaviour
{
public:
	FollowPath();
	~FollowPath();

	virtual void Update(Agent *pAgent, float deltaTime);
};

