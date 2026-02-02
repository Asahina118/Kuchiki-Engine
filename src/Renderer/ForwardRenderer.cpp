#include "Renderer/ForwardRenderer.h"

// normal shadow render pass
ForwardRenderer::ForwardRenderer(ShaderRegistry& shaderRegistry)
	: m_shaderRegistry(shaderRegistry)
{
}

void ForwardRenderer::ShadowRenderPass()
{
	/*
		render scene, bind to shadowFBO 
	*/
}

/*
	normal light rendering
*/
void ForwardRenderer::LightRenderPass(Scene& scene)
{
	/*
		get renderQueue from scene
	*/

	/*
		for (Entity in renderQueue) {

			Entity->shader->use();

			Entity->texture->bind();

			Entity->Mesh->bindVAO();

			glDrawElement();

		}
	*/
}

std::string ForwardRenderer::registerShader(const std::string& vertPath, const std::string& fragPath)
{
	return m_shaderRegistry.put(vertPath, fragPath);
}
