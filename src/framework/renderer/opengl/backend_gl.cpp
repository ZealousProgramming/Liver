#include "backend_gl.h"
#include "shader_gl.h"
#include "shader_program_gl.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sellas {
	// Data
	f32 quad_vertices[] = {
		 0.5f,   0.5f,  0.0f, // Top Right
		 0.5f,  -0.5f,  0.0f, // Bottom Right
		-0.5f,	-0.5f,  0.0f, // Bottom Left
		-0.5f,	 0.5f,  0.0f  // Top Left
	};

	u32 quad_indices[] = {
		0, 1, 3, // Top Right, Bottom Right, Top Left
		1, 2, 3	 // Bottom Right, Bottom Left, Top Left
	};

	RendererGL::~RendererGL() {
		if (vao != 0)
			glDeleteVertexArrays(1, &vao);

		if (vbo != 0)
			glDeleteBuffers(1, &vbo);

		if (ebo != 0)
			glDeleteBuffers(1, &ebo);

		default_shader_program->shutdown();

		auto _count = default_shader_program.use_count();
	}

	const bool RendererGL::initialize() {
		ShaderGL vertex_shader = ShaderGL();
		ShaderGL fragment_shader = ShaderGL();

		vertex_shader.initialize(GL_VERTEX_SHADER);
		fragment_shader.initialize(GL_FRAGMENT_SHADER);

		vertex_shader.source();
		if (!vertex_shader.compile()) {
			vertex_shader.shutdown();
			fragment_shader.shutdown();
			return false;
		}

		fragment_shader.source();
		if (!fragment_shader.compile()) {
			vertex_shader.shutdown();
			fragment_shader.shutdown();
			return false;
		}
		
		default_shader_program = std::make_shared<ShaderProgramGL>();
		default_shader_program->initialize();
		default_shader_program->attach(vertex_shader.get_handle());
		default_shader_program->attach(fragment_shader.get_handle());
		default_shader_program->link();

		vertex_shader.shutdown();
		fragment_shader.shutdown();
		
		// Setup VAO, VBO and EBO
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);

		// Order of binds matter
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quad_indices), quad_indices, GL_STATIC_DRAW);

		// Configure the Vertex Attributes
		constexpr static auto SIZE_F32 = sizeof(f32);

		// glVertexAttribPointer(
		// GLuint index, GLint size, 
		// GLenum type, GLboolean normalized, 
		// GLsizei stride, const void *pointer)
		// 
		// index - Cooresponds to the layout location in the shader.
		// size - The size of the vertex attribute (position in the default 
		// shader is a vec3, so 3 values)
		// data_type - The data type of the data that is being passed to the
		// shader
		// should_normalize - Whether we want the data to become normalized
		// stride - The space in between vertex data (In the case of our
		// position, the start of the next vertex position is our position
		// + the size of 3 f32s, 12 bytes in this case)
		// offset - Where the start of the vertex data is in the buffer. For
		// position, it'll be 0 since the first 12 bytes belong to our 
		// positional data.
		glVertexAttribPointer(
			0,						// index
			3,						// size
			GL_FLOAT,				// type
			GL_FALSE,				// should_normalize
			3 * SIZE_F32,			// stride
			static_cast<void*>(0)	// offset
		);

		// Enable the first vertex attribute to be used
		glEnableVertexAttribArray(0);

		// Unbind the vbo
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// NOTE(devon): Do NOT unbind the ebo while the vao is still active.
		// It will not store the current EBO otherwise.
		
		// Unbind it until it is needed again
		glBindVertexArray(0);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		return true;
	}

	void RendererGL::on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) {
		glViewport(0, 0, new_width, new_height);
	}
	
	void RendererGL::start_draw() {
		bind_shader();
		bind_vao(vao);
	}

	void RendererGL::bind_shader() const {
		default_shader_program->bind();
	}

	void RendererGL::bind_vao(const u32 vao_handle) const {
		glBindVertexArray(vao_handle);
	}

	void RendererGL::clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RendererGL::clear_color(const f32 r, const f32 g, const f32 b) {
		glClearColor(r, g, b, 1.0);
	}
	
	void RendererGL::submit() {
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererGL::draw_indexed() {

	}

}