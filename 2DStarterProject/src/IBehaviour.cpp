#include "IBehaviour.h"

IBehaviour::IBehaviour()
{
}
IBehaviour::~IBehaviour()
{
}

void IBehaviour::SetPath(std::list<Graph::Node*>* path)
{
	m_path = path;

	//Path index starts at 1 instead of 0, since the agent should already be at the first node
	m_index = 1;
}