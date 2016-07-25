#pragma once

#include "IBehaviour.h"
#include "Graph.h"

class GetRandomNode : public IBehaviour
{
public:
	GetRandomNode();
	GetRandomNode(int minDistance, int maxDistance, Graph* graph);
	virtual ~GetRandomNode();

	virtual Result Update(Agent *pAgent, float deltaTime);

private:
	Graph* m_graph = nullptr;
	
	int m_minDistance = 0;
	int m_maxDistance = 0;
};

