#pragma once

#include <list>
#include <vector>
#include "Vector2.h"

class Graph
{
public:
	struct Node;
	struct Edge
	{
		Edge();
		Edge(Node* a_connection);
		Edge(Node* a_connection, float a_cost);

		Node* connection;
		float cost;
	};
	struct Node
	{
		Node();
		Node(Vector2 a_pos);
		Node(Vector2 a_pos, float a_gScore, Node* a_parent);		Vector2 position;
		float gScore;
		Node* parent;

		std::vector<Graph::Edge> connections;
	};

	Graph();
	virtual ~Graph();

	/*Node *AddNode(float xPos, float yPos);*/
	void AddConnection(Node* n1, Node* n2);

	void GenerateNodeGrid(float sizeX, float sizeY, float padding);

	void FindDijkstrasPath(Node* start, Node* endNode, std::list<Node*> &outPath);
	void FindNodesInRange(std::vector<Node*> &outNodes, float xPos, float yPos, float radious);

	std::vector<Node*> nodes;
};

