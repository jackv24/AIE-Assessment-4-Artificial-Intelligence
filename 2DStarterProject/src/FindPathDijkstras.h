#pragma once

#include "IBehaviour.h"
#include "PathNode.h"
#include <queue>

class FindPathDijkstras : public IBehaviour
{
public:
	FindPathDijkstras();
	~FindPathDijkstras();

	virtual void Update(Agent *pAgent, float deltaTime);

	void FindPath(PathNode* a_nodeA, PathNode* a_nodeB);

private:
	std::queue<PathNode*> m_nodeQueue;
};

