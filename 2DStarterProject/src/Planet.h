#pragma once

#include "SceneNode.h"
#include "Texture.h"
#include "SpriteBatch.h"
#include "Vector2.h"

class Planet : public SceneNode
{
public:
	Planet(const char* texturePath);
	Planet(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale);
	~Planet();

	void Draw(SpriteBatch* spriteBatch);

	void Update(float rotateSpeed);

private:
	Texture* m_sprite;
};

