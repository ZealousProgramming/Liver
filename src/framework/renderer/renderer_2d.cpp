#include "renderer_2d.h"
#include "opengl/backend_gl.h"

namespace Sellas {

	RendererBackend* Renderer2D::backend = new RendererGL();

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

	void Renderer2D::clear() {
		Renderer2D::backend->clear();
	}

	void Renderer2D::clear_color(const f32 r, const f32 g, const f32 b) {
		Renderer2D::backend->clear_color(r, g, b);
	}
}