#include "Texture/Texture.h"
#include <glad/glad.h>

#include <stb_image/stb_image.h>
#include "Logger/KuchikiLogger.h"

Texture::Texture(const std::string& texturePath, const std::string& textureType)
	: m_texturePath(texturePath), m_textureType(textureType)
{
	glGenTextures(1, &m_id);
	if (loadFromFile(texturePath))
		quill::info(g_logger, "Loaded texture from file {}", texturePath);
	else
		quill::error(g_logger, "Failed to load texture from file {}", texturePath);
}

uint32_t Texture::getId() const
{
	return m_id;
}

bool Texture::loadFromFile(const std::string& texturePath)
{
	glBindTexture(GL_TEXTURE_2D, m_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int32_t width, height, nrChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	if (!data)
		return false;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}
