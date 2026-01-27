#pragma once

#include "Window/Window.h"
#include "Camera/Camera.h"

#include <vector>

typedef struct Mesh {
	uint32_t VAO;
	Shader shader;
	uint32_t textureId;

	Mesh(uint32_t VAO = 0, uint32_t shaderId = 0, uint32_t textureId)
		: VAO(VAO), textureId(textureId) {
		shader = 
	}
};

class TestScene
{
public:
	TestScene(Window& window);
	void render();

private:
	Window& m_window;
	Camera m_mainCamera;

	std::vector<Mesh> m_renderBuffers;
	
	void startFrame();
	void endFrame();
	void initScene();

	std::vector<Shader> m_shaderBuffers;

	Shader& getShader(const std::string& name);

	// Meshes
	void initTestCube();
};