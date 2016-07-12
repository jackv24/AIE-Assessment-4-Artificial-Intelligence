#include "Composite.h"

Composite::Composite()
{
}
Composite::~Composite()
{
	//Delete and remove all children
	for (unsigned int i = 0; i < m_childBehaviours.size(); i++)
	{
		delete m_childBehaviours[i];
	}
	m_childBehaviours.clear();
}

void Composite::AddChild(IBehaviour* behaviour)
{
	m_childBehaviours.push_back(behaviour);
}