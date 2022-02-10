#include "shader_program_gl.h"
#include "shader_gl.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Sellas {
	void ShaderProgramGL::initialize() {
		handle = glCreateProgram();
	}

	void ShaderProgramGL::shutdown() {
		glDeleteProgram(handle);
	}

	void ShaderProgramGL::attach(const ShaderHandle shader_handle) {
		glAttachShader(handle, shader_handle);
	}

	void ShaderProgramGL::bind() {
		glUseProgram(handle);
	}

	void ShaderProgramGL::link() {
		const i32 LOG_BUFFER_SIZE = 512;
		i32 link_result;
		char link_log[LOG_BUFFER_SIZE];

		glLinkProgram(handle);
		
		glGetProgramiv(handle, GL_LINK_STATUS, &link_result);

		if (!link_result) {
			glGetProgramInfoLog(handle, LOG_BUFFER_SIZE, NULL, link_log);
			std::cout << "[Sellas][Renderer][Shader][GL] ERROR: Shader program failed to LINK!\n";
		}
		
	}

}
