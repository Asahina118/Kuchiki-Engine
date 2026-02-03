#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image/stb_image.h>

#include "Window/Window.h"
#include "Shader/Shader.h"
#include "Entities/Shapes.h"
#include "Inputs/InputHandler.h"
#include "Camera/Camera.h"

#include "Logger/KuchikiLogger.h"

#include "Scene/TestScenes/TestScene.h"

#include "Kuchiki.h"

extern quill::Logger* global_logger_a;

// temp debug
void printCameraInfo(const Camera& camera)
{
	glm::vec3 camPos = camera.getPosition();
	std::cout << camPos.x << ", " << camPos.y << ", " << camPos.z << std::endl;
}

void Kuchiki::run()
{
	quill::info(g_logger, "Hello from {}!", std::string_view{"Kuchiki Engine"});

	const unsigned SCR_WIDTH = 800;
	const unsigned SCR_HEIGHT = 600;
	Camera camera;
	Window window(SCR_WIDTH, SCR_HEIGHT);
	InputHandler inputHandler(window, camera);
	

	Shader shader("GLSL/cube.vert", "GLSL/cube.frag");
	shader.use();
	shader.setInt("simpleTexture", 0);
	shader.setMat4("model", glm::mat4(1.0f));


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

	// texture loading	
	 
	uint32_t texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int32_t width, height, nrChannels;
	std::string_view textureFilePath = "Resources/container.jpg";
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(textureFilePath.data(), &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		quill::info(g_logger, "Loaded texture from {}", textureFilePath);
	}
	else {
		quill::error(g_logger, "Failed to load texture");
	}
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
	// end of texture loading

	//TestScene testScene(window);
	//testScene.render();

	while (!window.windowShouldClose()) {
		inputHandler.processInput();

		printCameraInfo(camera);//debug

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// render ============================================
		shader.use();
		shader.setMat4("view", camera.getViewMatrix());
		shader.setMat4("proj", camera.getProjMatrix());

		glBindVertexArray(VAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// end render ========================================

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	/*
		Scene scene = Scene.setup();
		Renderer.render(scene);
	*/

	glfwTerminate();
}

std::string Kuchiki::registerShader(const std::string& vertPath, const std::string& fragPath)
{
	std::cout << "TESTING" << std::endl;
	return "";
}
