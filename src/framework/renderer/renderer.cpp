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

	void Renderer::start_draw() {

	}

	void Renderer::end_draw() {

	}

	void Renderer::submit() {

	}
}