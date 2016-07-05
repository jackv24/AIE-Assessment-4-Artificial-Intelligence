#pragma once

#include "Agent.h"

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agent *pAgent, float deltaTime) = 0;
	virtual void SetPath(std::list<Graph::Node*>* path);

protected:
	std::list<Graph::Node*>* m_path = nullptr;
	int m_index = 0;
};

