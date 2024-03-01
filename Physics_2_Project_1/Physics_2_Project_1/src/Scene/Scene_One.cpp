#include "Scene_One.h"
#include "../AppSettings.h"
#include <Graphics/MathUtils.h>

using namespace MathUtilities;

Scene_One::~Scene_One()
{
}

Scene_One::Scene_One(ApplicationWindow* window)
{
	mWindow = window;
}

void Scene_One::Start()
{
	mMainCamera = new GameCamera();
	mMainCamera->name = "MainCamera";
	mMainCamera->InitializeCamera(PERSPECTIVE, GAME_RESOLUTION_WIDTH, GAME_RESOLUTION_HEIGHT, 0.1f, 500.0f, 45.0f);
	mMainCamera->transform.SetPosition(glm::vec3(0, 5, 30));
	mMainCamera->transform.SetRotation(glm::vec3(-15, 0, 0));

	Light* dirLight = new Light();
	dirLight->transform.SetScale(glm::vec3(0.1f));
	dirLight->transform.SetPosition(glm::vec3(0, 0, 3));
	dirLight->transform.SetRotation(glm::vec3(10, 40, 0));
	dirLight->InitializeLight(Directional);
	dirLight->intensity = 0.6;
}

void Scene_One::Update()
{

}

void Scene_One::Render()
{
}
