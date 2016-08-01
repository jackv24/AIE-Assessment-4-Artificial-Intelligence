#include "GetFurthestNode.h"

GetFurthestNode::GetFurthestNode()
{
}
GetFurthestNode::GetFurthestNode(Agent* target, Graph* graph)
{
	m_target = target;
	m_graph = graph;
}
GetFurthestNode::~GetFurthestNode()
{
}

GetFurthestNode::Result GetFurthestNode::Update(Agent *pAgent, float deltaTime)
{
	if (m_graph != nullptr && m_target != nullptr)
	{
		Vector2 agentPos(pAgent->GetPosition().x, pAgent->GetPosition().y);
		Vector2 targetPos(m_target->GetPosition().x, m_target->GetPosition().y);

		Graph::Node* start = m_graph->FindClosestNode(agentPos);
		Graph::Node* end = nullptr;

		//Find furthest node from target
		float maxDistance = 0;
		for (Graph::Node* node : m_graph->nodes)
		{
			if (Vector2(targetPos - node->position).magnitude() > maxDistance)
			{
				maxDistance = Vector2(targetPos - node->position).magnitude();
				end = node;
			}
		}

		std::list<Graph::Node*>* path = m_graph->FindAStarPath(start, end);
		pAgent->SetPath(path);

		return Success;
	}

	return Failure;
}