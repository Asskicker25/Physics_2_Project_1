#include <Physics/Thread/PhysicsEngineThread.h>
#include <Graphics/Panels/EditorLayout.h>

#include "SoftBodyApplication.h"

void SoftBodyApplication::SetUp()
{
	physicsThread = InitializePhysicsThread(0.01f);


	viewportCamera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 500.0f, 45.0f);
	viewportCamera->transform.SetPosition(glm::vec3(0, 5, 30));
	viewportCamera->transform.SetRotation(glm::vec3(-20, 0, 0));
	viewportCamera->applyPostProcessing = true;

	EditorLayout::GetInstance().SetMaximizeState(true);

	PhysicsEngine::GetInstance().gravity.y = -9.8f / 3.0f;
	PhysicsEngine::GetInstance().fixedStepTime = 0.01f;

	sceneOne = new Scene_One(this);

	SceneManager::GetInstance().AddScene("SceneOne", sceneOne);
	SceneManager::GetInstance().ChangeScene("SceneOne");

#pragma region Skybox

	skyBox->meshes[0]->material = new SkyBoxMaterial();
	SkyBoxMaterial* skyboxMat = skyBox->meshes[0]->material->AsSkyBoxMaterial();

	skyboxMat->skyBoxTexture->LoadTexture({
		"Assets/Textures/Skybox/Right.jpg",
		"Assets/Textures/Skybox/Left.jpg",
		"Assets/Textures/Skybox/Up.jpg",
		"Assets/Textures/Skybox/Down.jpg",
		"Assets/Textures/Skybox/Front.jpg",
		"Assets/Textures/Skybox/Back.jpg",
		});

#pragma endregion

	physicsThread->isRunning = true;
}

void SoftBodyApplication::Update()
{
	PhysicsEngine::GetInstance().Update(Timer::GetInstance().deltaTime);
}

void SoftBodyApplication::Render()
{
}

void SoftBodyApplication::Shutdown()
{
	if (physicsThread != nullptr)
	{
		physicsThread->isAlive = false;
		WaitForSingleObject(physicsThread->threadHandle, INFINITE);
		CloseHandle(physicsThread->threadHandle);
		DeleteCriticalSection(&physicsThread->softBodyUpdateModelData);
	}
	delete physicsThread;
	delete sceneOne;
}

void SoftBodyApplication::ProcessInput(GLFWwindow* window)
{
}

void SoftBodyApplication::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void SoftBodyApplication::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}

void SoftBodyApplication::OnPlayStateChanged(bool state)
{
}
