#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class GetPath : public IBehaviour
{
public:
	GetPath();
	GetPath(Agent* target, Graph* graph);
	virtual ~GetPath();

	virtual Result Update(Agent *pAgent, float deltaTime);

private:
	Graph* m_graph = nullptr;
	Agent* m_target = nullptr;
};

