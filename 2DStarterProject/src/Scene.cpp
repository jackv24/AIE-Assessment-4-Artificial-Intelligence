#include "Scene.h"

void Scene::SetRoot(SceneNode* node)
{
	m_scene_root = node;
}

void Scene::UpdateTransforms()
{
	m_scene_root->UpdateTransforms();
}