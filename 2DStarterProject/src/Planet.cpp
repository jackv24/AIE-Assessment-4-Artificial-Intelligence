#include "Planet.h"

Planet::Planet(const char* texturePath)
{
	m_sprite = new Texture(texturePath);

	Matrix3 scale = Matrix3::CreateScale(Vector3(1, 1, 1));
	Matrix3 rotation = Matrix3::CreateRotation(0);
	Matrix3 translation = Matrix3::CreateTranslation(Vector3(640, 360, 1));

	m_local_transform = scale * rotation * translation;
}
Planet::Planet(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale)
{
	m_sprite = new Texture(texturePath);

	Matrix3 m_scale = Matrix3::CreateScale(scale);
	Matrix3 m_rotation = Matrix3::CreateRotation(rotation);
	Matrix3 m_translation = Matrix3::CreateTranslation(position);

	m_local_transform = m_scale * m_rotation * m_translation;
}
Planet::~Planet()
{
}

void Planet::Draw(SpriteBatch* spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(m_sprite, m_global_transform);
}

void Planet::Update(float rotateSpeed)
{
	m_local_transform = m_local_transform * Matrix3::CreateRotation(1.0f * rotateSpeed);
}
