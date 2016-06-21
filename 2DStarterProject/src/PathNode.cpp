#include "PathNode.h"

PathNode::PathNode()
{
	position = Vector2(0, 0);
	gScore = 0;
	parent = nullptr;
}
PathNode::PathNode(Vector2 a_pos)
{
	position = a_pos;
	gScore = 0;
	parent = nullptr;
}
PathNode::PathNode(Vector2 a_pos, float a_gScore, PathNode* a_parent)
{
	position = a_pos;
	gScore = a_gScore;
	parent = a_parent;
}
PathNode::~PathNode()
{
}
