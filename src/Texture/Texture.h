#pragma once

#include <cinttypes>
#include <string>

class Texture
{
public:
	Texture();

	uint32_t id() const;
	bool isLoaded() const;

	bool loadFromFile(const std::string& filePath);

private:
	uint32_t m_id;
	bool m_loaded;
};