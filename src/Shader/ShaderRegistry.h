#pragma once

#include "Shader/Shader.h"
#include <vector>
#include <memory>

class ShaderRegistry 
{
public:
	ShaderRegistry();
	Shader& getShader(uint32_t idx);
	uint32_t createShader(const std::string& vertexPath, const std::string& fragmentPath);
private:
	std::vector<std::unique_ptr<Shader>> m_shaders;
};