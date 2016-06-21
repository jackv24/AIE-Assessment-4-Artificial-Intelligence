#pragma once

class PathNode;

class PathEdge
{
public:
	PathEdge();
	PathEdge(PathNode* a_connection);
	PathEdge(PathNode* a_connection, float a_cost);
	~PathEdge();

	PathNode* connection;

	float cost;
};

