#pragma once

#include <glm/glm.hpp>
#include <array>

namespace Shapes
{
	inline constexpr std::array<float, 9> triangleVertices = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};

	inline constexpr std::array<float, 9> triangleVerticesTextured = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};

	struct Square 
	{
		inline static constexpr std::array<float, 20> vertices = {
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		inline static constexpr std::array<float, 20> verticesTextured = {
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		inline static constexpr std::array<uint32_t, 6> indices = {
			0, 1, 2,
			0, 2, 3
		};
	};

	struct Cube
	{
        // back culling + normal + texCoords
        inline static constexpr std::array<float, 108> vertices = {
            // Back face
            -0.5f, -0.5f, -0.5f, // Bottom-left
             0.5f,  0.5f, -0.5f, // top-right
             0.5f, -0.5f, -0.5f, // bottom-right         
             0.5f,  0.5f, -0.5f, // top-right
            -0.5f, -0.5f, -0.5f, // bottom-left
            -0.5f,  0.5f, -0.5f, // top-left
            // Front face
            -0.5f, -0.5f,  0.5f, // bottom-left
             0.5f, -0.5f,  0.5f, // bottom-right
             0.5f,  0.5f,  0.5f, // top-right
             0.5f,  0.5f,  0.5f, // top-right
            -0.5f,  0.5f,  0.5f, // top-left
            -0.5f, -0.5f,  0.5f, // bottom-left
            // Left face
            -0.5f,  0.5f,  0.5f, // top-right
            -0.5f,  0.5f, -0.5f, // top-left
            -0.5f, -0.5f, -0.5f, // bottom-left
            -0.5f, -0.5f, -0.5f, // bottom-left
            -0.5f, -0.5f,  0.5f, // bottom-right
            -0.5f,  0.5f,  0.5f, // top-right
            // Right face
             0.5f,  0.5f,  0.5f, // top-left
             0.5f, -0.5f, -0.5f,  // bottom-right
             0.5f,  0.5f, -0.5f,  // top-right         
             0.5f, -0.5f, -0.5f,  // bottom-right
             0.5f,  0.5f,  0.5f,  // top-left
             0.5f, -0.5f,  0.5f,  // bottom-left     
             // Bottom face
             -0.5f, -0.5f, -0.5f,  // top-right
              0.5f, -0.5f, -0.5f,  // top-left
              0.5f, -0.5f,  0.5f,  // bottom-left
              0.5f, -0.5f,  0.5f,  // bottom-left
             -0.5f, -0.5f,  0.5f,  // bottom-right
             -0.5f, -0.5f, -0.5f,  // top-right
             // Top face
             -0.5f,  0.5f, -0.5f,  // top-left
              0.5f,  0.5f,  0.5f,  // bottom-right
              0.5f,  0.5f, -0.5f,  // top-right     
              0.5f,  0.5f,  0.5f,  // bottom-right
             -0.5f,  0.5f, -0.5f,  // top-left
             -0.5f,  0.5f,  0.5f   // bottom-left        
        };
        inline static constexpr std::array<float, 108> normals = {
            // Back face
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f, -1.0f,  1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			// Front face
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			// Left face
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            // Right face
            1.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            1.0f,  0.0f,  0.0f,
            // Bottom face
            0.0f, -1.0f,  0.0f,
            0.0f, -1.0f,  0.0f,
            0.0f, -1.0f,  0.0f,
            0.0f, -1.0f,  0.0f,
            0.0f, -1.0f,  0.0f,
            0.0f, -1.0f,  0.0f,
            // Top face
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f
        };
        inline static constexpr std::array<float, 72> texCoords = {
            // Back face
            0.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,
            // Front face
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            // Left face
            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,
            // Right face
            1.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            // Bottom face
            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,
            // Top face
            0.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            0.0f, 0.0f
        };
    };


    template<size_t N>
    std::vector<float> toVec(const float(&arr)[N]) 
    {
        return { arr, arr + N };
    }

    template<size_t N>
    std::vector<float> toVec(const std::array<float, N>& arr)
    {
        return { arr.begin(), arr.end() };
    }
}
