#include "FollowPath.h"
#include "Vector2.h"
#include "Vector3.h"
#include <iostream>
#include <algorithm>

FollowPath::FollowPath()
{
}
FollowPath::~FollowPath()
{
}

void FollowPath::Update(Agent *pAgent, float deltaTime)
{
	Vector2 agentPos(pAgent->GetPosition().x, pAgent->GetPosition().y);

	static int index = 0;

	if (m_path != nullptr && m_path->size() > 0)
	{
		if (index < m_path->size())
		{
			std::list<Graph::Node*>::iterator it = m_path->begin();
			std::advance(it, index++);

			pAgent->SetPosition(Vector3((*it)->position.x, (*it)->position.y, 1));
		}
		else
			index = 0;
	}
}

void FollowPath::SetPath(std::list<Graph::Node*>* path)
{
	m_path = path;
	
	std::cout << "Set path" << std::endl;
}