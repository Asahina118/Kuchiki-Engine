#pragma once

#include "Window/Window.h"
#include "Camera/Camera.h"
#include "Shader/Shader.h"

#include <vector>

struct Mesh {
	uint32_t VAO;
	uint32_t shaderId;
	uint32_t textureId;

	Mesh(uint32_t VAO, uint32_t shaderId, uint32_t textureId)
		: VAO(VAO), textureId(textureId), shaderId(shaderId) {
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

	std::vector<Mesh> m_meshBuffer;
	std::vector<Shader> m_shaderBuffer;

	//std::vector<uint32_t> m_shaderBuffer;
	
	void startFrame();
	void endFrame();
	void initScene();


	void initMeshes();

	Shader& getShader(const std::string& name);

	// Meshes
	void initTestCube();
};