#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class GetFurthestNode : public IBehaviour
{
public:
	GetFurthestNode();
	GetFurthestNode(Agent* target, Graph* graph);
	virtual ~GetFurthestNode();

	virtual Result Update(Agent *pAgent, float deltaTime);

private:
	Graph* m_graph = nullptr;
	Agent* m_target = nullptr;
};

