#pragma once

#include "Window/Window.h"
#include "Camera/Camera.h"

#include <quill/SimpleSetup.h>

class TestScene
{
public:
	TestScene(Window& window);
	void render();

private:
	Window& m_window;
	Camera m_mainCamera;

	quill::v11::Logger* m_logger;
	
	void startFrame();
	void endFrame();
	void initScene();

	// Meshes
	void initTestCube();
};