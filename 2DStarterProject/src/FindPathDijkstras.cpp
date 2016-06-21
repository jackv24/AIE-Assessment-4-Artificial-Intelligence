#include "FindPathDijkstras.h"

FindPathDijkstras::FindPathDijkstras()
{
}
FindPathDijkstras::~FindPathDijkstras()
{
}

void FindPathDijkstras::Update(Agent *pAgent, float deltaTime)
{
	//Don't follow path of node queue is empty
	if (m_nodeQueue.empty())
		return;


}

void FindPathDijkstras::FindPath(PathNode* a_nodeA, PathNode* a_nodeB)
{
	//Procedure FindPathDijkstras(startNode, List of potentialEndNodes)
	//	Let openList be a List of Nodes
	//	Let closedList be a List of Nodes
	//	Let endNode be a Node set to NULL
	//	Add startNode to openList
	//	While openList is not empty
	//	Sort openList by Node.gScore
	//	Let currentNode = first item in openList
	//	// Process the node, do what you want with it. EG:
	//	if currentNode is one of the potentialEnd
	//		endNode = currentNode
	//		break out of loop
	//		remove currentNode from openList
	//		Add currentNode to closedList
	//		for all connections c in currentNode
	//			Add c.connection to openList if not in closedList
	//			c.connection.gScore = currentNode.gScore + c.cost
	//			c.connection.parent = currentNode
	//			// Calculate Path
	//			Let path be a List of Vector2
	//			Let currentNode = endNode;
	//While currentNode != NULL
	//	Add currentNode.position to path
	//	currentNode = currentNode.parent
}