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
	m_index = 0;
}