#include "Scene/TestScenes/TestScene.h"

#include "Entities/Shapes.h"
#include "Texture/Texture.h"
#include "Logger/KuchikiLogger.h"
#include "Shader/Shader.h"

#include <stb_image/stb_image.h>

TestScene::TestScene(Window& window)
	: m_window(window)
{
	Camera m_mainCamera;
	m_meshBuffer.reserve(10);
	m_shaderBuffer.reserve(10);

	m_meshBuffer.emplace_back(5u, 3u);

	Mesh tempMesh = m_meshBuffer[0];

	quill::info(g_logger, "testing m_meshBuffer: {} {}", tempMesh.textureId, tempMesh.VAO);
}

void TestScene::render()
{
	initScene();

	if (!m_window.windowShouldClose()) {
		startFrame();

		for (Mesh mesh : m_meshBuffer) {
			glUseProgram(mesh.shaderId);

		}

		endFrame();
	}
}

void TestScene::initScene()
{
	stbi_set_flip_vertically_on_load(true);
}

void TestScene::startFrame()
{

}

void TestScene::endFrame()
{

}

void TestScene::initTestCube()
{
	uint32_t VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Shapes::Square::verticesTextured.size() * sizeof(float), Shapes::Square::verticesTextured.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Shapes::Square::indices.size() * sizeof(uint32_t), Shapes::Square::indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);

	Texture testCubeTexture("Resources/container.jpg");
	Shader shader("GLSL/cube.vert", "GLSL/cube.frag");
	m_shaderBuffer.emplace_back(shader);
	m_meshBuffer.emplace_back(VAO, shader.m_id, testCubeTexture.getId());
}

//uint32_t TestScene::loadTexture()
//{
	//uint32_t texture;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//int32_t width, height, nrChannels;
	//std::string_view textureFilePath = "Resources/container.jpg";
	//stbi_set_flip_vertically_on_load(true);
	//unsigned char* data = stbi_load(textureFilePath.data(), &width, &height, &nrChannels, 0);
	//if (data) {
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//	quill::info(logger, "Loaded texture from {}", textureFilePath);
	//}
	//else {
	//	quill::error(logger, "Failed to load texture");
	//}
	//stbi_image_free(data);
	//glBindTexture(GL_TEXTURE_2D, 0);
	//return texture;
//}

Shader& TestScene::getShader(const std::string& name)
{
	//auto it = m_shaderRegistry.find(name);
	//if (it == m_shaderRegistry.end()) {
	//	quill::error(g_logger, "Shader {} not found.", name);
	//	throw
	//}
	//return *it->second;
}
