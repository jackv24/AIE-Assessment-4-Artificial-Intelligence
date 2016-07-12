#pragma once

#include "Agent.h"

class IBehaviour
{
public:
	enum Result
	{
		Success,
		Failure,
		Pending
	};

	IBehaviour();
	virtual ~IBehaviour();

	virtual Result Update(Agent *pAgent, float deltaTime) = 0;
};

