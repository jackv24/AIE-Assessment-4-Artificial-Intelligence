#include "Application2D.h"

#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include <vector>
#include <list>

#include "MathLib.h"
#include "Scene.h"
#include "Agent.h"
#include "Graph.h"

#include <iostream>
#include <fstream>
#include <ctime>

#include "FollowPath.h"

Scene* scene;
Agent* moonAgent;

Graph* graph;
std::list<Graph::Node*> pathNodes;

bool isKeyHeld = false;

Texture* circleTex;

Application2D::Application2D() {
	
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_font = new Font("./bin/font/consolas.ttf", 32);

	graph = new Graph();
	graph->GenerateNodeGrid(13, 24, 51);
	circleTex = new Texture("./bin/textures/circle.png");

	scene = new Scene();

	//Create sun as root
	moonAgent = new Agent("./bin/textures/Moon.png", Vector3(50, 50, 1), 0, Vector3(1, 1, 1));
	scene->SetRoot(moonAgent);
	moonAgent->AddBehaviour(new FollowPath());

	return true;
}

void Application2D::shutdown() {

	delete scene;
	delete moonAgent;
	delete graph;
	delete m_spriteBatch;
	delete m_font;
	delete circleTex;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	//Drawing sprites
	moonAgent->Update(deltaTime);

	scene->UpdateTransforms();

	//Detect keypress
	if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;

			int x, y;
			getCursorPosition(x, y);
			//Find node at position (within range) take screen height because of how the screen height is found
			Graph::Node* node = graph->FindClosestNode(Vector2((float)x, 720.0f - (float)y));

			if (node)
			{
				graph->start = graph->FindClosestNode(Vector2(moonAgent->GetPosition().x, moonAgent->GetPosition().y));

				graph->end = node;

				graph->FindAStarPath(graph->start, graph->end, pathNodes);
				moonAgent->SetPath(&pathNodes);
			}
		}
	}
	else if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;
			int x, y;
			getCursorPosition(x, y);

			graph->AddNode(Vector2((float)x, 720.0f - (float)y));
		}
	}
	else if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE))
	{
		int x, y;
		getCursorPosition(x, y);

		if (graph->RemoveNode(graph->FindNode(Vector2((float)x, 720.0f - (float)y), 25.0f)))
			pathNodes.clear();
	}
	//Press button to pathfind
	/*
	else if (isKeyPressed(GLFW_KEY_D))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;

			//If there is a start and end node, find a path between them
			if (graph->start && graph->end)
			{
				//Start timer
				std::clock_t start;
				start = std::clock();

				//graph->FindDijkstrasPath(graph->start, graph->end, pathNodes);
				graph->FindDijkstrasPath(graph->start, graph->end, pathNodes);

				//Print out time taken to execute pathfinding function (in milliseconds)
				std::cout << "Time taken (Dijkstra's): " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << std::endl;

				agent->SetPath(&pathNodes);
			}
		}
	}
	else if (isKeyPressed(GLFW_KEY_A))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;

			//If there is a start and end node, find a path between them
			if (graph->start && graph->end)
			{
				//Start timer
				std::clock_t start;
				start = std::clock();

				//graph->FindDijkstrasPath(graph->start, graph->end, pathNodes);
				graph->FindAStarPath(graph->start, graph->end, pathNodes);

				//Print out time taken to execute pathfinding function (in milliseconds)
				std::cout << "Time taken (A*): " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << std::endl;

				agent->SetPath(&pathNodes);
			}
		}
	}*/
	else
		isKeyHeld = false;

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//Draw agents
	moonAgent->Draw(m_spriteBatch);
	
	//Draw graph of nodes
	for (unsigned int i = 0; i < graph->nodes.size(); i++)
	{
		//Set node colour
		m_spriteBatch->setSpriteColor(0.75f, 0.75f, 0.75f, 1);

		if (pathNodes.size() > 0)
		{
			//Set colour of path nodes
			if (std::find(pathNodes.begin(), pathNodes.end(), graph->nodes[i]) != pathNodes.end())
				m_spriteBatch->setSpriteColor(1, 1, 0, 1);
		}

		//Draw node
		m_spriteBatch->drawSprite(circleTex, graph->nodes[i]->position.x, graph->nodes[i]->position.y, 16, 16, 0, 0, 0.5f, 0.5f);

		m_spriteBatch->setSpriteColor(0, 0, 0, 0.1f);
		//Draw edges
		for (Graph::Edge edge : graph->nodes[i]->connections)
		{
			m_spriteBatch->drawLine(graph->nodes[i]->position.x, graph->nodes[i]->position.y, edge.connection->position.x, edge.connection->position.y, 2.0f, 1);
		}
	}

	// done drawing sprites
	m_spriteBatch->end();	
}