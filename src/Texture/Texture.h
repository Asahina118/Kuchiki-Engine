#pragma once

#include <cinttypes>
#include <string>

class Texture
{
public:
	Texture(const std::string& texturePath, const std::string& textureType);

	//Texture(const std::string& )

	uint32_t getId() const;

	bool loadFromFile(const std::string& texturePath);

private:
	uint32_t m_id;
	bool m_loaded;
	std::string m_texturePath;
	std::string m_textureType;
};