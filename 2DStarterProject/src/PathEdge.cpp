#include "PathEdge.h"
#include "PathNode.h"

PathEdge::PathEdge()
{
	connection = nullptr;
	cost = 0;
}
PathEdge::PathEdge(PathNode* a_connection)
{
	connection = a_connection;
	cost = 0;
}
PathEdge::PathEdge(PathNode* a_connection, float a_cost)
{
	connection = a_connection;
	cost = a_cost;
}
PathEdge::~PathEdge()
{
}
