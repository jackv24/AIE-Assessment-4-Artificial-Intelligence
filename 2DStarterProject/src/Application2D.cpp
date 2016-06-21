#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include <vector>

#include "MathLib.h"
#include "Scene.h"
#include "Agent.h"

#include <iostream>
#include <fstream>

Scene* scene;

Agent* agent;

bool isKeyHeld = false;

Application2D::Application2D() {
	
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	scene = new Scene();

	//Create sun as root
	agent = new Agent("textures/trump.png", Vector3(640, 360, 1), 0, Vector3(1, 1, 1));
	scene->SetRoot(agent);

	return true;
}

void Application2D::shutdown() {

	delete scene;

	delete agent;

	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	//Drawing sprites
	agent->Update(deltaTime);

	scene->UpdateTransforms();

	//Detect keypress
	//Save
	if (isKeyPressed(GLFW_KEY_K))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;
			std::cout << "Saved tree" << std::endl;

			std::ofstream file("data.dat", std::ios::out | std::ios::binary);
			
			agent->SaveTree(file);

			file.close();
		}
	}
	//Load
	else if (isKeyPressed(GLFW_KEY_L))
	{
		if (!isKeyHeld)
		{
			isKeyHeld = true;
			std::cout << "Loaded tree" << std::endl;

			std::ifstream file("data.dat", std::ios::in | std::ios::binary);

			agent->LoadTree(file);

			file.close();
		}
	}
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

	agent->Draw(m_spriteBatch);

	// done drawing sprites
	m_spriteBatch->end();	
}