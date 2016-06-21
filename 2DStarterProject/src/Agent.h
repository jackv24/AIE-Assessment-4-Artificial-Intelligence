#pragma once

class IBehaviour;

#include <vector>
#include "SceneNode.h"
#include "Texture.h"
#include "Vector2.h"
#include "SpriteBatch.h"

class Agent : public SceneNode
{
public:
	Agent(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale);
	~Agent();

	void Update(float deltaTime);
	void Draw(SpriteBatch* spriteBatch);

	void AddForce(const Vector2 force);

protected:
	std::vector<IBehaviour*> m_behaviours;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;

	Texture* m_sprite;
};
