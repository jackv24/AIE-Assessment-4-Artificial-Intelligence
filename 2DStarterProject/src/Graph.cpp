#include "Graph.h"
#include <algorithm>

//Edge functions
Graph::Edge::Edge()
{
	connection = nullptr;
	cost = 0;
}
Graph::Edge::Edge(Node* a_connection)
{
	connection = a_connection;
	cost = 0;
}
Graph::Edge::Edge(Node* a_connection, float a_cost)
{
	connection = a_connection;
	cost = a_cost;
}

//Node functions
Graph::Node::Node()
{
	position = Vector2(0, 0);
	gScore = 0;
	parent = nullptr;
}
Graph::Node::Node(Vector2 a_pos)
{
	position = a_pos;
	gScore = 0;
	parent = nullptr;
}
Graph::Node::Node(Vector2 a_pos, float a_gScore, Node* a_parent)
{
	position = a_pos;
	gScore = a_gScore;
	parent = a_parent;
}

//Graph functions
Graph::Graph()
{

}
Graph::~Graph()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
	nodes.clear();
}

// Add's a node at the given location, return the created node.
//Graph::Node* Graph::AddNode(float xPos, float yPos)
//{
//
//}
// this function connects the 2 nodes by adding an edge
// cost is automaticly set to the distance between n1 and n2
void Graph::AddConnection(Node *n1, Node *n2)
{
	Vector2 displacement = n2->position - n1->position;

	n1->connections.push_back(Edge(n2, displacement.magnitude()));
	//n2->connections.push_back(Edge(n1, displacement.magnitude()));
}

void Graph::GenerateNodeGrid(float sizeX, float sizeY, float padding)
{
	for (int y = 0; y < sizeX; y++)
	{
		for (int x = 0; x < sizeY; x++)
		{
			nodes.push_back(new Node(Vector2(x * padding, y * padding)));
		}
	}

	for (Node* src : nodes)
	{
		for (Node* dest : nodes)
		{
			float distance = Vector2(dest->position - src->position).magnitude();

			if (distance < 65)
				AddConnection(src, dest);
		}
	}
}

// Searches the graph starting from the "start" node untill one of
// the "potential end node's" are found.
// the resulting path is added to the "outPath" list.
void Graph::FindDijkstrasPath(Node* start, Node* endNode, std::list<Node*> &outPath)
{
	std::list<Node*> openList;
	std::list<Node*> closeList;
	Node* currentNode;

	openList.push_back(start);

	while (!openList.empty())
	{
		//Sort list by gScore (using lambda sort function)
		openList.sort([](Node* a, Node* b) { return a->gScore < b->gScore; });

		currentNode = openList.front();

		if (currentNode == endNode)
			break;

		openList.remove(currentNode);
		closeList.push_back(currentNode);

		for (Edge c : currentNode->connections)
		{
			if (std::find(closeList.begin(), closeList.end(), c.connection) != closeList.end())
				openList.push_back(c.connection);

			c.connection->gScore = currentNode->gScore + c.cost;
			c.connection->parent = currentNode;
		}
	}

	std::list<Vector2> path;
	currentNode = endNode;

	while (currentNode != NULL)
	{
		path.push_back(currentNode->position);
		currentNode = currentNode->parent;
	}
}
// Helper function, populates “outNodes” with nodes that are within
// a circular area (xPos, yPos, radious)
void Graph::FindNodesInRange(std::vector<Node*> &outNodes, float xPos, float yPos, float radious)
{

}