#include "Agent.h"
#include "IBehaviour.h"

Agent::Agent(const char* texturePath, const Vector3 position, const float rotation, const Vector3 scale)
{
	m_sprite = new Texture(texturePath);

	Matrix3 m_scale = Matrix3::CreateScale(scale);
	Matrix3 m_rotation = Matrix3::CreateRotation(rotation);
	Matrix3 m_translation = Matrix3::CreateTranslation(position);

	m_local_transform = m_scale * m_rotation * m_translation;
}
Agent::~Agent()
{
	delete m_sprite;

	//Deleting root node will call destructors on children
	delete m_behaviourTree;
}

void Agent::Update(float deltaTime)
{
	//TODO: Sensing calculations
	//TODO: Thinking calculations
	//Add or remove behaviours from m_behaviours

	//Acting
	//Calling update on the root node of the tree
	if(m_behaviourTree != nullptr)
		m_behaviourTree->Update(this, deltaTime);

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

void Agent::SetBehaviourTree(IBehaviour* behaviour)
{
	m_behaviourTree = behaviour;
}

void Agent::SetPath(std::list<Graph::Node*>* path)
{
	m_path = path;
}
std::list<Graph::Node*>* Agent::GetPath()
{
	return m_path;
}