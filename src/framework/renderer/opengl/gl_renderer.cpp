#include "gl_renderer.h"

#include <GLFW/glfw3.h>

#include <iostream>

namespace Sellas {
	bool GLRenderer::initialize() const {
		std::cout << "[Sellas][Renderer][GL] Initializing..\n";
		return true;
	}

	void GLRenderer::shutdown() {
		std::cout << "[Sellas][Renderer][GL] Shutting down..\n";
	}
	
	void GLRenderer::on_resize(const i16 new_width, const i16 new_height) {
		
	}

	void GLRenderer::on_draw_begin() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 0.0, 1.0, 1.0);
	}

	void GLRenderer::on_draw_end() {

	}

	bool GLRenderer::on_draw_frame(const f32 delta_time) const {

		return true;
	}


}