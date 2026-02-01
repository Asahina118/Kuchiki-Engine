#include "Shader/ShaderRegistry.h"
#include "Shader/Shader.h"
#include "Logger/KuchikiLogger.h"

#include <iostream>

ShaderRegistry::ShaderRegistry()
	: defaultShaderVert("GLSL/default.vert"), defaultShaderFrag("GLSL/default.frag")
{
	m_shaderRegistry.reserve(10);
	put(defaultShaderVert, defaultShaderFrag);
}

Shader& ShaderRegistry::getShader(const std::string& key)
{
	auto it = m_shaderRegistry.find(key);

	if (it == m_shaderRegistry.end()) {
		quill::error(g_logger, "Cannot find the specified Shader from key: {}", key);
		return *m_shaderRegistry.find(getKey(defaultShaderVert, defaultShaderFrag))->second;
	}
	return *it->second;
}

Shader& ShaderRegistry::getShader(const std::string& vertPath, const std::string& fragPath)
{
	std::string key = getKey(vertPath, fragPath);
	auto it = m_shaderRegistry.find(key);

	if (it == m_shaderRegistry.end()) {
		quill::error(g_logger, "Cannot find the specified Shader from path: {} {}", vertPath, fragPath);
		return *m_shaderRegistry.find(getKey(defaultShaderVert, defaultShaderFrag))->second;
	}
	return *it->second;
}

std::string ShaderRegistry::put(const std::string& vertPath, const std::string& fragPath)
{
	const std::string& key = getKey(vertPath, fragPath);
	m_shaderRegistry.emplace(key, std::make_unique<Shader>(vertPath, fragPath));
	//std::cout << "The returned Shader has id: " << m_shaderRegistry.find(vertPath + fragPath)->second->m_id << std::endl;

	return key;
}

std::string ShaderRegistry::getKey(const std::string& vertPath, const std::string& fragPath)
{
	return vertPath + fragPath;
}




