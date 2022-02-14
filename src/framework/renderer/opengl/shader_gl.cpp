#include "shader_gl.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Liver {
	// TODO(devon): Remove once file handling is up and running
	const char* vertex_shader_source = 
		"#version 460 core\n"
		"layout (location = 0) in vec3 in_position;\n"
		"layout (location = 1) in vec3 in_color;\n"
		"layout (location = 2) in vec2 in_texcoord;\n"
		"\n"
		"out vec3 frag_color;"
		"out vec2 texcoord;"
		"\n"
		"uniform mat4 model;"
		"uniform mat4 view;"
		"uniform mat4 projection;"
		"\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(in_position.xyz, 1.0);\n"
		"	frag_color = in_color;\n"
		"	texcoord = in_texcoord;\n"
		"}\0";

	const char* fragment_shader_source = 
		"#version 460 core\n"
		"out vec4 out_color;\n"
		"\n"
		"in vec3 frag_color;\n"
		"in vec2 texcoord;\n"
		"\n"
		"uniform sampler2D uni_texture;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	out_color = texture(uni_texture, texcoord) * vec4(frag_color, 1.0f);\n"
		"}\n\0";
	
	// ---

	void ShaderGL::initialize(const u32 type) {
		shader_type = type;
		handle = glCreateShader(type);
	}

	void ShaderGL::shutdown() {
		glDeleteShader(handle);
	}

	void ShaderGL::source() {
		glShaderSource(handle, 1, (shader_type == GL_VERTEX_SHADER ? &vertex_shader_source : &fragment_shader_source), NULL);

	}

	const bool ShaderGL::compile() {
		const i32 LOG_BUFFER_SIZE = 512;
		i32 source_result;
		char source_log[LOG_BUFFER_SIZE];

		glCompileShader(handle);

		glGetShaderiv(handle, GL_COMPILE_STATUS, &source_result);

		if (!source_result) {
			glGetShaderInfoLog(handle, LOG_BUFFER_SIZE, NULL, source_log);
			std::cout << "[Liver][Renderer][Shader][GL] ERROR: " << shader_type_to_string(shader_type) << " failed to COMPILE!\n" << source_log << "\n";
			return false;
		}

		return true;
	}

	const char* ShaderGL::shader_type_to_string(const u32 type) const {
		switch (type) {
			case GL_VERTEX_SHADER:
				return "Vertex";
			case GL_FRAGMENT_SHADER:
				return "Fragment";
			default:
				return "Unknown Shader Type";
		}
	}
}