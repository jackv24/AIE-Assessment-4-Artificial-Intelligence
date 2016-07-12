#include "Selector.h"
#include <algorithm>

Selector::Selector()
{
}
Selector::~Selector()
{
}

Selector::Result Selector::Update(Agent *pAgent, float deltaTime)
{
	//Make the pendign child the current child instead
	IBehaviour* child = m_pendingChild;
	m_pendingChild = nullptr;
	
	//If current child is null, start at the first child
	if (child == nullptr)
		child = m_childBehaviours.front();

	//While the child is in the list
	while (std::find(m_childBehaviours.begin(), m_childBehaviours.end(), child) != m_childBehaviours.end())
	{
		//Get result of updating child
		Result result = child->Update(pAgent, deltaTime);

		//If the child succeeded, OR succeeded
		if (result == Success)
			return Success;
		//If the child failed, move on to the next child
		else if (result == Failure)
			child++;
		//If the child is still pending...
		else if (result == Pending)
		{
			//Set it as the pending child and return Pending
			m_pendingChild = child;
			return Pending;
		}
	}

	//Return failure if no child succeeded
	return Failure;
}