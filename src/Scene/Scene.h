#pragma once
#include "Camera/Camera.h"
#include "Window/Window.h"

class Scene
{
public:
	virtual ~Scene() = default;
	virtual void init() = 0;
	virtual void update(float dt) = 0;

};