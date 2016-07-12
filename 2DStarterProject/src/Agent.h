#pragma once

class IBehaviour;

#include "SceneNode.h"
#include "Texture.h"
#include "Vector2.h"
#include "SpriteBatch.h"
#include "Graph.h"

class Agent : public SceneNode
{
public:
	Agent(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale);
	virtual ~Agent();

	void Update(float deltaTime);
	void Draw(SpriteBatch* spriteBatch);

	void AddForce(const Vector2 force);

	void SetBehaviourTree(IBehaviour* behaviour);

	void SetPath(std::list<Graph::Node*>* path);
	std::list<Graph::Node*>* GetPath();

protected:
	IBehaviour* m_behaviourTree = nullptr; //root node of tree

	std::list<Graph::Node*>* m_path = nullptr;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;

	Texture* m_sprite;
};

