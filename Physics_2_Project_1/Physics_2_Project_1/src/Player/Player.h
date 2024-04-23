#pragma once
#include <Physics/Softbody/SoftBodyForVertex.h>
#include "../Scene/Scene_One.h"

using namespace Verlet;

class Player : public SoftBodyForVertex
{
public:

	Player(Scene_One* sceneOne);
};

