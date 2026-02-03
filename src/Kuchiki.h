#pragma once
#include <vector>
#include <string>

#include "Entities/Entity.h"

namespace Kuchiki
{
	void init();
	void setScene();
	void run();
	extern std::vector<Entity> renderQueue;
	std::string registerShader(const std::string& vertPath, const std::string& fragPath);
}