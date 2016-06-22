#pragma once

#include "IBehaviour.h"
#include "Graph.h"
#include <queue>

class FindPathDijkstras : public IBehaviour
{
public:
	FindPathDijkstras(Graph* a_graph);
	~FindPathDijkstras();

	virtual void Update(Agent *pAgent, float deltaTime);

private:
	Graph* m_graph;
	Graph::Node* m_path;
};

