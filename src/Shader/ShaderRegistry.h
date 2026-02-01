#pragma once

#include "Shader/Shader.h"
#include <vector>
#include <memory>
#include <unordered_map>

class ShaderRegistry 
{
public:
	ShaderRegistry();

	Shader& getShader(const std::string& key);
	Shader& getShader(const std::string& vertPath, const std::string& fragPath);
	std::string put(const std::string& vertPath, const std::string& fragPath);
	std::string getKey(const std::string& vertPath, const std::string& fragPath);

private:
	std::unordered_map<std::string, std::unique_ptr<Shader>> m_shaderRegistry;
	const std::string& defaultShaderVert;
	const std::string& defaultShaderFrag;
};

/*
NOTE on how i want to implement a shader structure:

std::unordered_map<key, &Shader>
where key = vertPath + fragPath for simplicity for now

store a std::vector<std::string> for every Mesh in the scene. (to record the Shader paths vertPath + fragPath)

When meshes initialize the shaders, check the registry for shader, if shader is loaded into the std::unordered_map, then dont do anything about it

in renderpass, 
	for every mesh
		for (std::string key : std::vector<std::string>>)
			get &Shader by key

*/