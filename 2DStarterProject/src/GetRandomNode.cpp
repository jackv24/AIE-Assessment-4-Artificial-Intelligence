#include "GetRandomNode.h"

GetRandomNode::GetRandomNode()
{
}
GetRandomNode::GetRandomNode(int minDistance, int maxDistance, Graph* graph)
{
	m_graph = graph;

	m_minDistance = minDistance;
	m_maxDistance = maxDistance;
}
GetRandomNode::~GetRandomNode()
{
}

GetRandomNode::Result GetRandomNode::Update(Agent *pAgent, float deltaTime)
{
	if (m_graph != nullptr)
	{
		//Get agent position
		Vector2 agentPos(pAgent->GetPosition().x, pAgent->GetPosition().y);

		//Get random direction and normalise
		Vector2 direction((float(rand()) / float(RAND_MAX)) - 0.5f, (float(rand()) / float(RAND_MAX)) - 0.5f);
		direction.normalise();

		//Get new position in this direction
		Vector2 targetPos((direction * ((rand() % (m_maxDistance - m_minDistance + 1) + m_minDistance))) + agentPos);
		//Vector2 targetPos(500, 600);

		//Find closest nodes to these positions
		Graph::Node* start = m_graph->FindClosestNode(agentPos);
		Graph::Node* end = m_graph->FindClosestNode(targetPos);

		std::list<Graph::Node*>* path = m_graph->FindAStarPath(start, end);
		pAgent->SetPath(path);

		return Success;
	}

	return Failure;
}