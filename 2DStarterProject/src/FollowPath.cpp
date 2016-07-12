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

FollowPath::Result FollowPath::Update(Agent *pAgent, float deltaTime)
{
	Vector2 agentPos(pAgent->GetPosition().x, pAgent->GetPosition().y);

	std::list<Graph::Node*>* path = pAgent->GetPath();

	if (path != nullptr && path->size() > 0)
	{
		if (m_index < path->size())
		{
			std::list<Graph::Node*>::iterator it = path->begin();
			std::advance(it, m_index);

			if ((pAgent->GetPosition() - (*it)->position).magnitude() < 5)
				m_index++;

			Vector3 direction = (pAgent->GetPosition() - (*it)->position) * -1;
			direction.normalise();
			pAgent->Translate(direction * deltaTime * 200);

			//Still following path
			return Pending;
		}

		//Successfully followed path
		m_index = 0;

		return Success;
	}

	//No path to follow
	return Failure;
}