#include "StaticPlatforms.h"

#include <Physics/PhysicsObject.h>

StaticPlatforms::StaticPlatforms(Scene_One* sceneOne) : mSceneOne { sceneOne }
{ 
	name = "StaticPlatforms";
	InitializeEntity(this);

	LoadModels();
}

void StaticPlatforms::Start()
{
}

void StaticPlatforms::Update(float deltaTime)
{
}

void StaticPlatforms::Render()
{
}

void StaticPlatforms::OnDestroy()
{
}

void StaticPlatforms::LoadModels()
{

	PhysicsObject* cubeModel = new PhysicsObject();
	cubeModel->LoadModel("res/Models/DefaultCube.fbx");
	cubeModel->name = "Cube 1";
	cubeModel->transform.SetPosition(glm::vec3(0.12f, 0.0f, 22.05f));
	cubeModel->transform.SetScale(glm::vec3(6.0f, 1.0f, 1.0f));

	cubeModel->InitializePhysics(AABB, STATIC, SOLID);

	mSceneOne->mListOfPhyObjects.push_back(cubeModel);

}
