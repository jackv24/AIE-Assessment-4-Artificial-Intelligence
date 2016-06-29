#include "Graph.h"
#include <limits>
#include <algorithm>
#include <time.h>

//Edge functions
Graph::Edge::Edge()
{
	connection = nullptr;
	cost = 1;
}
Graph::Edge::Edge(Node* a_connection)
{
	connection = a_connection;
	cost = 1;
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
	hScore = 0;
	fScore = 0;
	parent = nullptr;
}
Graph::Node::Node(Vector2 a_pos)
{
	position = a_pos;
	gScore = 0;
	hScore = 0;
	fScore = 0;
	parent = nullptr;
}
Graph::Node::Node(Vector2 a_pos, float a_gScore, Node* a_parent)
{
	position = a_pos;
	gScore = a_gScore;
	hScore = 0;
	fScore = 0;
	parent = a_parent;
}

//Graph functions
Graph::Graph()
{
	start = nullptr;
	end = nullptr;
}
Graph::~Graph()
{
	for (unsigned int i = 0; i < nodes.size(); i++)
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
	n2->connections.push_back(Edge(n1, displacement.magnitude()));
}
Graph::Node* Graph::FindNode(Vector2 pos, float maxDistance)
{
	for (Node* node : nodes)
	{
		if (Vector2(pos - node->position).magnitude() <= maxDistance)
			return node;
	}

	return nullptr;
}
Graph::Node* Graph::FindClosestNode(Vector2 pos)
{
	float maxDistance = std::numeric_limits<float>::max();

	Node* closestNode = nullptr;

	for (Node* node : nodes)
	{
		if (Vector2(pos - node->position).magnitude() < maxDistance)
		{
			maxDistance = Vector2(pos - node->position).magnitude();
			closestNode = node;
		}
	}

	return closestNode;
}

//Generates a grid of nodes
void Graph::GenerateNodeGrid(float sizeX, float sizeY, float padding)
{
	srand((unsigned int)time(NULL));

	for (int y = 0; y < sizeX; y++)
	{
		for (int x = 0; x < sizeY; x++)
		{
			if(rand() % 3 > 0)
				nodes.push_back(new Node(Vector2(x * padding + padding, y * padding + padding)));
		}
	}

	for (Node* src : nodes)
	{
		for (Node* dest : nodes)
		{
			float distance = Vector2(dest->position - src->position).magnitude();

			if (distance < 100 && src != dest)
				AddConnection(src, dest);
		}
	}
}

//Adds a new node, and connections
void Graph::AddNode(Vector2 position)
{
	//Create and add new node
	nodes.push_back(new Node(position));

	//Add connections if within distance
	for (Node* src : nodes)
	{
		for (Node* dest : nodes)
		{
			float distance = Vector2(dest->position - src->position).magnitude();

			//If within arbitrary distance, add connection
			if (distance < 100 && src != dest)
				AddConnection(src, dest);
		}
	}
}
bool Graph::RemoveNode(Node* node)
{
	//Make sure there is a node to be removed
	if (node == nullptr)
		return false;

	bool isRemoved = false;

	//For every connection from every node connected to the node to be deleted...
	for (int i = node->connections.size() - 1; i >= 0; i--)
		for (int j = node->connections[i].connection->connections.size() - 1; j >= 0; j--)
			//...erase any connections to this node
			if (node->connections[i].connection->connections[j].connection == node)
			{
				node->connections[i].connection->connections.erase(node->connections[i].connection->connections.begin() + j);
				isRemoved = true;
			}

	//Erase the node from the graph
	nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
	//Delete the node from memory (which also deletes it's own edges)
	delete node;

	start = nullptr;
	end = nullptr;

	return isRemoved;
}

// Searches the graph starting from the "start" node untill one of
// the "potential end node's" are found.
// the resulting path is added to the "outPath" list.
void Graph::FindDijkstrasPath(Node* startNode, Node* endNode, std::list<Node*> &outPath)
{
	for (Node* node : nodes)
	{
		node->gScore = std::numeric_limits<float>::max();
		node->parent = nullptr;
	}

	std::list<Node*> openList;
	std::list<Node*> closeList;
	Node* currentNode;

	openList.push_back(startNode);

	startNode->gScore = 0;

	while (!openList.empty())
	{
		//Sort list by gScore (using lambda sort function)
		openList.sort([](Node* a, Node* b) { return a->gScore < b->gScore; });

		//Current node should be the start of the sorted list
		currentNode = openList.front();

		//If the current node is the end node, the path has been found. Break;
		if (currentNode == endNode)
			break;

		//Remove currentnode from the openlist and add to closelist
		openList.remove(currentNode);
		closeList.push_back(currentNode);

		//For each connection from the current node
		for (Edge c : currentNode->connections)
		{
			//If this connection is not in the close list, add to the open list
			if (std::find(closeList.begin(), closeList.end(), c.connection) == closeList.end())
				openList.push_back(c.connection);

			//If this connection is shorter
			if (currentNode->gScore + c.cost < c.connection->gScore)
			{
				c.connection->gScore = currentNode->gScore + c.cost;
				c.connection->parent = currentNode;
			}
		}
	}

	std::list<Node*> path;
	currentNode = endNode;

	//Follow path backwards to get output path
	while (currentNode != NULL)
	{
		path.push_front(currentNode);
		currentNode = currentNode->parent;
	}

	outPath = path;
}
//A* pathfinding (modification of Dijkstra's)
void Graph::FindAStarPath(Node* startNode, Node* endNode, std::list<Node*> &outPath)
{
	for (Node* node : nodes)
	{
		node->gScore = std::numeric_limits<float>::max();
		node->parent = nullptr;
	}

	std::list<Node*> openList;
	std::list<Node*> closeList;
	Node* currentNode;

	openList.push_back(startNode);

	startNode->gScore = 0;

	while (!openList.empty())
	{
		//Sort list by gScore (using lambda sort function)
		openList.sort([](Node* a, Node* b) { return a->fScore < b->fScore; });

		//Current node should be the start of the sorted list
		currentNode = openList.front();

		//If the current node is the end node, the path has been found. Break;
		if (currentNode == endNode)
			break;

		//Remove currentnode from the openlist and add to closelist
		openList.remove(currentNode);
		closeList.push_back(currentNode);

		//For each connection from the current node
		for (Edge c : currentNode->connections)
		{
			//If this connection is shorter
			if ((currentNode->gScore + c.cost < c.connection->gScore))
			{
				c.connection->gScore = currentNode->gScore + c.cost;
				c.connection->hScore = (c.connection->position - endNode->position).magnitude();
				c.connection->fScore = c.connection->gScore + c.connection->hScore;
				c.connection->parent = currentNode;
			}

			//If this connection is not in the close list, add to the open list
			if (std::find(closeList.begin(), closeList.end(), c.connection) == closeList.end())
				openList.push_back(c.connection);
		}
	}

	std::list<Node*> path;
	currentNode = endNode;

	//Follow path backwards to get output path
	while (currentNode != NULL)
	{
		path.push_front(currentNode);
		currentNode = currentNode->parent;
	}

	outPath = path;
}