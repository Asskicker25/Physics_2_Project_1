#include "Player.h"

Player::Player(Scene_One* sceneOne)
{
	LoadModel("Assets/Models/Rope_2.fbx");
	name = "Player";
	transform.SetPosition(glm::vec3(0.0f, 5.0f, 22.0f));
	transform.SetScale(glm::vec3(0.1f));
	showDebugModels = false;

	mNodeRadius = 0.05f;
	mGravity = glm::vec3(0, -1, 0);

	InitializeSoftBody();

	//for (int i = 0; i < sceneOne->mListOfPhyObjects.size(); i++)
	//{
	//	AddCollidersToCheck(sceneOne->mListOfPhyObjects[i]);
	//}
}
