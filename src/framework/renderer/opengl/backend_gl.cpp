#include "backend_gl.h"

#include <GLFW/glfw3.h>

namespace Sellas {
	bool GLRenderer::initialize() const {
		return true;
	}

	void GLRenderer::on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) {
		glViewport(0, 0, new_width, new_height);
	}

	void GLRenderer::clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLRenderer::clear_color(const f32 r, const f32 g, const f32 b) {
		glClearColor(1.0, 0.0, 1.0, 1.0);
	}

	void GLRenderer::draw() {

	}
	void GLRenderer::draw_indexed() {

	}

}