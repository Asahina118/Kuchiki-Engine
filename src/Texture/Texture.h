#pragma once

#include <cinttypes>
#include <string>

class Texture
{
public:
	Texture(const std::string& filePath);

	uint32_t getId() const;
	bool isLoaded() const;

	bool loadFromFile(const std::string& filePath);

private:
	uint32_t m_id;
	bool m_loaded;
};