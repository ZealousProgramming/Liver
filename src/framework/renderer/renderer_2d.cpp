#include "renderer_2d.h"
#include "opengl/backend_gl.h"

namespace Sellas {

	// TODO(devon): Run an ifdef for the Graphics API defines
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

	void Renderer2D::start_draw() {
		Renderer2D::backend->start_draw();
	}

	void Renderer2D::bind_shader() {
		Renderer2D::backend->bind_shader();
	}

	void Renderer2D::submit() {
		Renderer2D::backend->submit();
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