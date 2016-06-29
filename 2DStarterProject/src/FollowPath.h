#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class FollowPath : public IBehaviour
{
public:
	FollowPath();
	~FollowPath();

	virtual void Update(Agent *pAgent, float deltaTime);
	virtual void SetPath(std::list<Graph::Node*>* path);

private:
	std::list<Graph::Node*>* m_path = nullptr;

	int m_index = 0;
};

