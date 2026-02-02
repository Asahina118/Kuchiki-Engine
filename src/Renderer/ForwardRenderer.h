#pragma once

#include "Entities/Entity.h"
#include "Entities/Mesh.h"
#include "Shader/Shader.h"
#include "Shader/ShaderRegistry.h"
#include "Scene/Scene.h"


/*
	simple shader renderer
*/
class ForwardRenderer {
public:

	ForwardRenderer(ShaderRegistry& m_shaderRegistry);
	
	void render(Scene& scene);

	std::string registerShader(const std::string& vertPath, const std::string& fragPath);

private:

	ShaderRegistry& m_shaderRegistry;
	uint32_t m_shadowFBO;

	void ShadowRenderPass();
	void LightRenderPass(Scene& scene);
};