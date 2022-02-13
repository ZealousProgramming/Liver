#include "renderer.h"
#include "renderer_2d.h"

namespace Sellas {

	bool Renderer::initialize() {
		std::cout << "[Sellas][Renderer] Initializing..\n";
		
		if (!Renderer2D::initialize()) {
			std::cout << "[Sellas][Renderer] ERROR: Renderer failed to initialize!\n";
			return false;
		}

		return true;
	}
	
	void Renderer::shutdown() {
		std::cout << "[Sellas][Renderer] Shutting down..\n";
		Renderer2D::shutdown();
	}

	void Renderer::on_resize(const i16 x, const i16 y, const i16 width, const i16 height) {
		Renderer2D::on_resize(x, y, width, height);
	}

	void Renderer::start_draw(const Camera& current_camera) {
		Renderer2D::clear_color(clear_r, clear_g, clear_b);
		Renderer2D::clear();
		Renderer2D::start_draw(current_camera);
	}

	void Renderer::end_draw() {

	}

	void Renderer::submit() {
		Renderer2D::submit();
	}
}