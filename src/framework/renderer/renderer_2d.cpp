#include "renderer_2d.h"
#include "opengl/backend_gl.h"

namespace Sellas {

	RendererBackend* Renderer2D::backend = new GLRenderer();

	bool Renderer2D::initialize() {

		if (!Renderer2D::backend->initialize()) {
			std::cout << "[Sellas][Renderer2D] ERROR: Backend failed to initialize!\n";
			return false;
		}

		return true;
	}

	void Renderer2D::shutdown() {
		delete Renderer2D::backend;
	}

	void Renderer2D::draw_quad() {

	}
	
	void Renderer2D::on_resize(const i16 x, const i16 y, const i16 width, const i16 height) {
		Renderer2D::backend->on_resize(x, y, width, height);
	}
}