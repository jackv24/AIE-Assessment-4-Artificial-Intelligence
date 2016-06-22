#include "Agent.h"
#include "IBehaviour.h"
#include "FindPathDijkstras.h"

Agent::Agent(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale, Graph* pathGraph)
{
	m_sprite = new Texture(texturePath);

	Matrix3 m_scale = Matrix3::CreateScale(scale);
	Matrix3 m_rotation = Matrix3::CreateRotation(rotation);
	Matrix3 m_translation = Matrix3::CreateTranslation(position);

	m_local_transform = m_scale * m_rotation * m_translation;

	m_behaviours.push_back(new FindPathDijkstras(pathGraph));
}
Agent::~Agent()
{
	delete m_sprite;
}

void Agent::Update(float deltaTime)
{
	//TODO: Sensing calculations
	//TODO: Thinking calculations
	//Add or remove behaviours from m_behaviours

	//Acting
	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		(*iter)->Update(this, deltaTime);

	//TODO: Physics stuff force, acceleration, velocity, etc...
}

void Agent::Draw(SpriteBatch* spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(m_sprite, m_global_transform);
}

void Agent::AddForce(const Vector2 force)
{
	m_local_transform = Matrix3::CreateTranslation(Vector3(force.x, force.y, 1)) * m_local_transform;
}