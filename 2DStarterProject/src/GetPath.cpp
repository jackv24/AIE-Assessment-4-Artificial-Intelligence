#include "GetPath.h"

GetPath::GetPath()
{
}
GetPath::GetPath(Agent* target, Graph* graph)
{
	m_target = target;
	m_graph = graph;
}
GetPath::~GetPath()
{
}

GetPath::Result GetPath::Update(Agent *pAgent, float deltaTime)
{
	if (m_graph != nullptr && m_target != nullptr)
	{
		Vector2 agentPos(pAgent->GetPosition().x, pAgent->GetPosition().y);
		Vector2 targetPos(m_target->GetPosition().x, m_target->GetPosition().y);

		Graph::Node* start = m_graph->FindClosestNode(agentPos);
		Graph::Node* end = m_graph->FindClosestNode(targetPos);

		std::list<Graph::Node*>* path = m_graph->FindAStarPath(start, end);
		pAgent->SetPath(path);

		return Success;
	}

	return Failure;
}