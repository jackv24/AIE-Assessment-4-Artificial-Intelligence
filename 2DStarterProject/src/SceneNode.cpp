#include "SceneNode.h"
#include <iostream>
#include <fstream>

SceneNode::SceneNode()
{
	m_parent = nullptr;

	m_local_transform = Matrix3::CreateIdentity();
}
SceneNode::~SceneNode()
{
	m_children.clear();
}

void SceneNode::SetParent(SceneNode* node)
{
	m_parent = node;
}
void SceneNode::AddChild(SceneNode* node)
{
	m_children.push_back(node);
	node->SetParent(this);
}
void SceneNode::RemoveChild(SceneNode* node)
{
	m_children.erase(std::find(m_children.begin(), m_children.end(), node));
	node->SetParent(nullptr);
}

void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
		m_global_transform = m_parent->m_global_transform * m_local_transform;
	else
		m_global_transform = m_local_transform;
	for (unsigned int i = 0; i < m_children.size(); ++i)
	{
		m_children[i]->UpdateTransforms();
	}
}

void SceneNode::SaveTree(std::ofstream& stream)
{
	if (stream.good())
		stream.write((char*)&m_local_transform, sizeof(m_local_transform));

	for (unsigned int i = 0; i < m_children.size(); ++i)
	{
		//Continue down tree, concatenating values
		m_children[i]->SaveTree(stream);
	}
}

void SceneNode::LoadTree(std::ifstream& stream)
{
	if (stream.good())
		stream.read((char*)&m_local_transform, sizeof(m_local_transform));

	for (unsigned int i = 0; i < m_children.size(); ++i)
	{
		m_children[i]->LoadTree(stream);
	}
}