#include <glad/glad.h>

#include <glm/glm.hpp>

#include "Logger/KuchikiLogger.h"
#include "Entities/Mesh.h"


Mesh::Mesh(std::vector<float> positions)
{
	if (positions.size() % 3 != 0) {
		quill::error(g_logger, "mesh construction failed: number of vertices is not divisible by 3");
		return;
	}

	m_vertices.reserve(positions.size()/3);
	for (int i = 0; i < positions.size(); i += 3) {
		m_vertices.emplace_back(
			glm::vec3(positions[i], positions[i + 1], positions[i + 2]),
			glm::vec3(0.0f),
			glm::vec2(0.0f),
			glm::vec3(0.0f),
			glm::vec3(0.0f)
		);
	}

	initBuffers();
}

Mesh::Mesh(std::vector<float> positions, std::vector<float> normals, std::vector<float> texCoords)
{
	if (positions.size()/3 != normals.size()/3 || normals.size()/3 != texCoords.size()/2) {
		quill::error(g_logger, "mesh construction failed: number of vertices does not match");
		return;
	}

	m_vertices.reserve(sizeof(Vertex)*positions.size()/3);

	for (int i = 0; i < positions.size() / 3; i++) {
		m_vertices.emplace_back(
			glm::vec3(positions[3*i], positions[3*i+1], positions[3*i+2]),
			glm::vec3(normals[3*i], normals[3*i+1], normals[3*i+2]),
			glm::vec2(texCoords[2*i], texCoords[2*i+1]),
			glm::vec3(0.0f),
			glm::vec3(0.0f)
		);
	}

	initBuffers();
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture> textures)
{
	// assume triangles? (dont even know if non triangles are allowed by OpenGL LMAO
}

Mesh::Mesh(std::vector<float> positions, std::vector<float> texCoords, std::vector<uint32_t> indices)
{
	if (positions.size()/3 != texCoords.size()/2) {
		quill::error(g_logger, "mesh construction failed: number of vertices does not match");
		return;
	}

	m_vertices.reserve(sizeof(Vertex)*positions.size()/3);

	for (int i = 0; i < positions.size() / 3; i++) {
		m_vertices.emplace_back(
			glm::vec3(positions[3*i], positions[3*i + 1], positions[3*i + 2]),
			glm::vec3(0.0f),
			glm::vec2(texCoords[2*i], texCoords[2*i + 1]),
			glm::vec3(0.0f),
			glm::vec3(0.0f)
		);
	}

	m_indices = indices;
	initBuffers();
}

uint32_t Mesh::getVAO()
{
	return m_VAO;
}

void Mesh::draw()
{
	
}

/*
	binding: 
	0 = position
	1 = normal
	2 = texCoords
	3 = tangent
	4 = bitangent
*/
void Mesh::initBuffers()
{
	uint32_t VBO;
	uint32_t EBO;

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(float), m_indices.data(), GL_STATIC_DRAW);

	size_t stride = sizeof(glm::vec3);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*) 0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*) offsetof(Vertex, Vertex::normal));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*) offsetof(Vertex, Vertex::texCoords));
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (void*) offsetof(Vertex, Vertex::tangent));
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, stride, (void*) offsetof(Vertex, Vertex::biTangent));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);

	/* future meshes ?
		

		
	*/ 

	glBindVertexArray(0);
}