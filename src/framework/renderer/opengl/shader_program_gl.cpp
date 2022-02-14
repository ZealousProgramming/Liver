#include "shader_program_gl.h"
#include "shader_gl.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Liver {
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
			std::cout << "[Liver][Renderer][Shader][GL] ERROR: Shader program failed to LINK!\n";
		}
		
	}
			
	const u32 ShaderProgramGL::get_uniform_location(const char* uniform_name) const {
		return glGetUniformLocation(handle, uniform_name);
	}

	// Uniform Setters
	void ShaderProgramGL::set_bool(const char* uniform_name, const bool value) const {
		int location = glGetUniformLocation(handle, uniform_name);
		glUniform1i(location, static_cast<int>(value));
	}
	
	void ShaderProgramGL::set_int(const char* uniform_name, const i32 value) const {
		int location = glGetUniformLocation(handle, uniform_name);
		glUniform1i(location, value);
	}

	void ShaderProgramGL::set_float(const char* uniform_name, const f32 value) const {
		int location = glGetUniformLocation(handle, uniform_name);
		glUniform1f(location, value);
	}

	void ShaderProgramGL::set_matrix4(const char* uniform_name, const glm::mat4& value) const {
		int location = glGetUniformLocation(handle, uniform_name);
		glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
	}
}
