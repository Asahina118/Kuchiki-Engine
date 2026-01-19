#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb_image/stb_image.h>

#include "Window/Window.h"

#include "Shaders/Shader.h"
#include "Entities/Shapes.h"

#include <quill/SimpleSetup.h>
#include <quill/LogFunctions.h>

int main()
{
	auto* logger = quill::simple_logger();
	quill::info(logger, "Hello from {}!", std::string_view{"Kuchiki Engine"});

	const unsigned SCR_WIDTH = 800;
	const unsigned SCR_HEIGHT = 600;
	Window window(SCR_WIDTH, SCR_HEIGHT);

	std::array<float, 9> cubeVertices = Shapes::cubeVertices;

	unsigned VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, cubeVertices.size(), cubeVertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, cubeVertices.size(), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	Shader shader("Shaders/GLSL/cube.vert", "Shaders/GLSL/cube.frag");


	//glShaderSource(vertexShader, 1, )

	while (!window.windowShouldClose()) {
		window.processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
