#include "Texture/Texture.h"
#include <glad/glad.h>

#include <stb_image/stb_image.h>

Texture::Texture()
{
	glGenTextures(1, &m_id);
}

bool Texture::loadFromFile(const std::string& filePath)
{
	//glBindTexture(GL_TEXTURE_2D, m_id);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//int32_t width, height, nrChannels;
	//stbi_set_flip_vertically_on_load(true);
	//unsigned char* data = stbi_load(filePath.c, &width, &height, &nrChannels, 0);
	//if (data) {
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//	quill::info(logger, "Loaded m_id from {}", textureFilePath);
	//}
	//else {
	//	quill::error(logger, "Failed to load m_id");
	//}
	//stbi_image_free(data);
	//glBindTexture(GL_TEXTURE_2D, 0);
	return false;
}
