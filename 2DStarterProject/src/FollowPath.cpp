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

	if (m_path != nullptr && m_path->size() > 0)
	{
		if (m_index < m_path->size())
		{
			std::list<Graph::Node*>::iterator it = m_path->begin();
			std::advance(it, m_index);

			if ((pAgent->GetPosition() - (*it)->position).magnitude() < 5)
				m_index++;

			Vector3 direction = (pAgent->GetPosition() - (*it)->position) * -1;
			direction.normalise();
			pAgent->Translate(direction * deltaTime * 200);
		}
	}
}