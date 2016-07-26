#include "CheckRange.h"

CheckRange::CheckRange()
{
}
CheckRange::CheckRange(Agent* target, float minDistance)
{
	m_minDistance = minDistance;
	m_target = target;
}
CheckRange::~CheckRange()
{
}

CheckRange::Result CheckRange::Update(Agent *pAgent, float deltaTime)
{
	if (m_target != nullptr)
	{
		float distance = (m_target->GetPosition() - pAgent->GetPosition()).magnitude();

		if(distance < m_minDistance)
			return Success;
	}

	return Failure;
}