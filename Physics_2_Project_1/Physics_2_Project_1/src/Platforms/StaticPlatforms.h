#pragma once

#include <Graphics/EntityManager/EntityManager.h>
#include <Graphics/Mesh/Model.h>
#include "../Scene/Scene_One.h"

class StaticPlatforms : public Entity
{
public:
	StaticPlatforms(Scene_One* sceneOne);

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;

private:
	void LoadModels();

	Scene_One* mSceneOne = nullptr;

	std::vector<Model*> mListOfModels;
};

