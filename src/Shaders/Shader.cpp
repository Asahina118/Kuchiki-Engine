#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <quill/SimpleSetup.h>
#include <quill/LogFunctions.h>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	initShader(vertexPath, fragmentPath);
}

std::string Shader::readFile(const std::string& filePath)
{
	std::ifstream file;
	std::stringstream stream;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		file.open(filePath);
		stream << file.rdbuf();
		m_vertexSource = stream.str();
	} 
	catch (std::ifstream::failure e) {
		quill::info(logger, "CWD: {}", std::filesystem::current_path().string());
		quill::error(logger, "Error reading file at {}:\n{}\n", filePath, e.what());
		return "";
	}

	return m_vertexSource;
}

void Shader::initShader(const char* vertexPath, const char* framentPath)
{
	uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexCodeString = readFile(vertexPath);
	const GLchar* vertexCode = vertexCodeString.c_str();
	glShaderSource(vertexShader, 1, &vertexCode, NULL);
	glCompileShader(vertexShader);
	checkCompilationErrors(vertexShader, vertexPath);

	// todo
}

void Shader::checkCompilationErrors(uint32_t shader, std::string_view filePath)
{
	GLchar infoLog[512];
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		quill::error(logger, "shader linking failed at {}\n{}\n", filePath, infoLog);
	}
	else {
		quill::info(logger, "shader compiled from {}\n", filePath);
	}
}
