#pragma once

#include "Shader/Shader.h"
#include <vector>
#include <memory>

class ShaderRegistry 
{
public:
	ShaderRegistry();
	Shader& getShader(uint32_t idx);
	uint32_t getOrCreateShader(const std::string& vertexPath, const std::string& fragmentPath);
private:
	std::vector<std::unique_ptr<Shader>> m_shaders;
};

/**
NOTE on how i want to implement a shader structure:

std::unordered_map<key, &Shader>
where key = vertPath + fragPath for simplicity for now

store a std::vector<std::string> for every Mesh in the scene. (to record the Shader paths vertPath + fragPath)

When meshes initialize the shaders, check the registry for shader, if shader is loaded into the std::unordered_map, then dont do anything about it

in renderpass, 
	for every mesh
		for (std::string key : std::vector<std::string>>)
			get &Shader by key

/