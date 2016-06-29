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
		Node(Vector2 a_pos, float a_gScore, Node* a_parent);

		Vector2 position;
		float gScore;
		float hScore;
		float fScore;
		Node* parent;

		std::vector<Graph::Edge> connections;
	};

	Graph();
	virtual ~Graph();

	void AddConnection(Node* n1, Node* n2);
	Node* FindNode(Vector2 mousePos, float maxDistance);
	Node* FindClosestNode(Vector2 mousePos);

	void GenerateNodeGrid(float sizeX, float sizeY, float padding);
	void AddNode(Vector2 position);
	bool RemoveNode(Node* node);

	void FindDijkstrasPath(Node* startNode, Node* endNode, std::list<Node*> &outPath);
	void FindAStarPath(Node* startNode, Node* endNode, std::list<Node*> &outPath);

	std::vector<Node*> nodes;

	Node* start = nullptr;
	Node* end = nullptr;
};

