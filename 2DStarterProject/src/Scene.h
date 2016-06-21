#pragma once

#include "SceneNode.h"

class Scene
{
public:
	void SetRoot(SceneNode* node);

	void UpdateTransforms();
private:
	SceneNode* m_scene_root;
};