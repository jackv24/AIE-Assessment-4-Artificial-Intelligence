#include "Sequence.h"

Sequence::Sequence()
{
}
Sequence::~Sequence()
{
}

Sequence::Result Sequence::Update(Agent *pAgent, float deltaTime)
{
	//Make the pendign child the current child instead
	IBehaviour* child = m_pendingChild;
	m_pendingChild = nullptr;

	//If current child is null, start at the first child
	if (child == nullptr)
		child = m_childBehaviours.front();

	//Find index of child
	unsigned int index = -1;
	for (int i = 0; i < m_childBehaviours.size(); i++)
	{
		if (m_childBehaviours[i] == child)
			index = i;
	}

	//While the child is in the list
	while (index < m_childBehaviours.size())
	{
		//Get result of updating child
		Result result = child->Update(pAgent, deltaTime);

		//If the child succeeded, advance to next child
		if (result == Success)
		{
			index++;
			if(index < m_childBehaviours.size())
				child = m_childBehaviours[index];
		}
		//If one child in the sequence fails, the sequence fails
		else if (result == Failure)
			return Failure;
		//If the child is still pending...
		else if (result == Pending)
		{
			//Set it as the pending child and return Pending
			m_pendingChild = child;
			return Pending;
		}
	}

	//Return success if no child failed
	return Success;
}