#pragma once

#include <vector>
#include "Vector2.h"
#include "PathEdge.h"

class PathNode
{
public:
	PathNode();
	PathNode(Vector2 a_pos);
	PathNode(Vector2 a_pos, float a_gScore, PathNode* a_parent);
	~PathNode();

	Vector2 position;

	float gScore;
	PathNode* parent;

	std::vector<PathEdge> connections;
};

