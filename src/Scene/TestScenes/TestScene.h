#pragma once

#include "Window/Window.h"
#include "Camera/Camera.h"
#include "Shader/Shader.h"
#include "Entities/Entity.h"
#include "Entities/Mesh.h"

#include <vector>

class TestScene
{
public:
	TestScene(Window& window);
	void render();

private:

	// temp
	struct Entity {
		Mesh mesh;
		std::string shaderKey;
		Texture texture;
	};

	Window& m_window;
	Camera m_mainCamera;

	std::vector<Entity> renderQueue;
	
	void startFrame();
	void endFrame();
	void initScene();


	void initMeshes();

	Shader& getShader(const std::string& name);

	// Meshes
	void initTestCube();
};