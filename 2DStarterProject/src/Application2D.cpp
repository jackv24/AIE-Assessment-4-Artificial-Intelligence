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

#include "Sequence.h"
#include "FollowPath.h"
#include "GetPath.h"

Scene* scene;
SceneNode* root;
Agent* player;
Agent* enemy;
Agent* target;

Graph* graph;

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

	//Create origin node as scene root
	root = new SceneNode();
	scene->SetRoot(root);

	//Create player
	player = new Agent("./bin/textures/player.png", Vector3(255, 255, 1), 0, Vector3(1, 1, 1));
	root->AddChild(player); //Child of scene root

	//Create enemy
	enemy = new Agent("./bin/textures/enemy.png", Vector3(50, 50, 1), 0, Vector3(1, 1, 1));
	root->AddChild(enemy);
	//Create enemy behavior tree
	Sequence* follow = new Sequence();
	follow->AddChild(new GetPath(player, graph));
	follow->AddChild(new FollowPath());
	//Set root behaviour
	enemy->SetBehaviourTree(follow);

	//Create target
	target = new Agent("./bin/textures/target.png", Vector3(408, 255, 1), 0, Vector3(1, 1, 1));
	root->AddChild(target);

	return true;
}

void Application2D::shutdown() {

	delete scene;
	//Deleting scene root also deletes all children recursively
	delete root;
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

	//Updating agents
	player->Update(deltaTime);
	enemy->Update(deltaTime);
	target->Update(deltaTime);

	scene->UpdateTransforms();

	//Detect keypress
	//Right click to create node
	if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
	{
		if (!isKeyHeld)
		{	//Key can not be held
			isKeyHeld = true;
			int x, y;
			getCursorPosition(x, y);

			graph->AddNode(Vector2((float)x, 720.0f - (float)y));
		}
	}
	//Middle click to delete node
	else if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE))
	{
		int x, y;
		getCursorPosition(x, y);

		graph->RemoveNode(graph->FindNode(Vector2((float)x, 720.0f - (float)y), 25.0f));
	}
	else //Makes sure that keys that can not be held are only called on key down
		isKeyHeld = false;

	// the application closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//Draw agents
	player->Draw(m_spriteBatch);
	enemy->Draw(m_spriteBatch);
	target->Draw(m_spriteBatch);
	
	//Draw graph of nodes
	for (unsigned int i = 0; i < graph->nodes.size(); i++)
	{
		//Set node colour
		m_spriteBatch->setSpriteColor(0.75f, 0.75f, 0.75f, 1);

		//Set enemy path colour
		if (enemy->GetPath()->size() > 0)
		{
			if (std::find(enemy->GetPath()->begin(), enemy->GetPath()->end(), graph->nodes[i]) != enemy->GetPath()->end())
				m_spriteBatch->setSpriteColor(1, 0.75f, 0.75f, 1);
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