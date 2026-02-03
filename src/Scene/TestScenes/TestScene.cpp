#include "Scene/TestScenes/TestScene.h"

#include "Entities/Shapes.h"
#include "Texture/Texture.h"
#include "Logger/KuchikiLogger.h"
#include "Shader/Shader.h"
#include "Shader/ShaderRegistry.h"
#include "Renderer/ForwardRenderer.h"

#include "Kuchiki.h"

#include <stb_image/stb_image.h>
#include <iostream>

TestScene::TestScene(Window& window)
	: m_window(window)
{
	Camera m_mainCamera;
	//quill::info(g_logger, "testing m_meshBuffer: {} {}", tempMesh.textureId, tempMesh.VAO);

	std::vector<float> tryoutVector = Shapes::toVec(Shapes::Cube::vertices);
	for (int i = 0; i < tryoutVector.size(); i++) {
		std::cout << tryoutVector[i] << ", ";
	}
	std::cout << std::endl;
}

void TestScene::render()
{
	initScene();
	initMeshes();

	// test
	ShaderRegistry shaderRegistry;
	shaderRegistry.put("GLSL/cube.vert", "GLSL/cube.frag");

	while (!m_window.windowShouldClose()) {
		startFrame();

		/*
			updates physics or other logics
		*/

		/*
			renderer only renders, does no any other things
		*/

		endFrame();
	}

	std::cout << "ending the testscene render" << std::endl;
}

void TestScene::initScene()
{
	stbi_set_flip_vertically_on_load(true);
}

void TestScene::initMeshes()
{
	initTestCube();
}

void TestScene::startFrame()
{

}

void TestScene::endFrame()
{
	glfwSwapBuffers(m_window.getWindow());
	glfwPollEvents();
}

void TestScene::initTestCube()
{
	Texture testCubeTexture("Resources/container.jpg", "_");
	std::string shaderKey = Kuchiki::registerShader("GLSL/cube.vert", "GLSL/cube.frag");

	Mesh mesh(Shapes::toVec(Shapes::Cube::vertices), Shapes::toVec(Shapes::Cube::normals), Shapes::toVec(Shapes::Cube::texCoords));

	//Mesh mesh(Shapes::toVec(Shapes::Cube::vertices), Shapes::Cube::normals, Shapes::Cube::texCoords);

	renderQueue.emplace_back(mesh, shaderKey, testCubeTexture);
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
