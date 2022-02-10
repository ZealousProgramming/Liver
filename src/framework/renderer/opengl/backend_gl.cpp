#include "backend_gl.h"
#include "shader_gl.h"
#include "shader_program_gl.h"

#include <GLFW/glfw3.h>

namespace Sellas {
	RendererGL::~RendererGL() {
		default_shader_program.use_count();
	}

	bool RendererGL::initialize() const {
		return true;
	}

	void RendererGL::on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) {
		glViewport(0, 0, new_width, new_height);
	}

	void RendererGL::clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RendererGL::clear_color(const f32 r, const f32 g, const f32 b) {
		glClearColor(r, g, b, 1.0);
	}

	void RendererGL::draw() {

	}
	void RendererGL::draw_indexed() {

	}

}