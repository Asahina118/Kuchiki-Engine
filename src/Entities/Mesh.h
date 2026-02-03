#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture/Texture.h"

class Mesh
{
public:

	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoords;
		glm::vec3 tangent;
		glm::vec3 biTangent;
	};

	Mesh(std::vector<float> positions);

	Mesh(std::vector<float> positions, std::vector<float> normals);

	Mesh(std::vector<float> positions, std::vector<float> normals, std::vector<float> texCoords);

	Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture> textures);

	// temp
	Mesh(std::vector<float> positions, std::vector<float> texCoords, std::vector<uint32_t> indices);

	uint32_t getVAO();

private:
	std::vector<uint32_t> m_indices;
	std::vector<Vertex> m_vertices;
	uint32_t m_VAO;

	void initBuffers();
};

/*
draw procedure:

1. for m_shaderKeys
		for m_textures:
				get textureType
				get texture id
				glActiveTexture
				bind VAO
				glDraw
*/