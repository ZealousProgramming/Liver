#include "application.h"
#include "window.h"

#include "../renderer/renderer.h"
#include "../renderer/opengl/gl_renderer.h"

#include <iostream>
#include <GLFW/glfw3.h>


namespace Sellas {
	bool Application::initialize(const char* window_title, const i16 window_width, const i16 window_height) {
		std::cout << "[Sellas][Application] Initializing..\n";

		if (on_start_fn == nullptr) {
			std::cout << "[Sellas][Application] ERROR: Application Start Function never assigned!\n";
			return false;
		}

		if (on_tick_fn == nullptr) {
			std::cout << "[Sellas][Application] ERROR: Application Tick Function never assigned!\n";
			return false;
		}

		if (on_render_fn == nullptr) {
			std::cout << "[Sellas][Application] ERROR: Application Render Function never assigned!\n";
			return false;
		}

		// Initialize GLFW
		if (!glfwInit()) {
			std::cout << "[Sellas][Application] ERROR: GLFW failed to initialize!\n";
			return false;
		}

		window = new Window(window_title, window_width, window_height);

		if (!window->initialize()) {
			std::cout << "[Sellas][Application] ERROR: Window failed to initialize!\n";
			return false;
		}

		renderer = new GLRenderer();

		renderer->initialize();

		return true;
	}

	void Application::shutdown() {
		renderer->shutdown();
		delete renderer;

		window->shutdown();
		delete window;

		std::cout << "[Sellas][Application] Shutting down..\n";
		glfwTerminate();
	}

	void Application::run() {
		while(!window->should_close()) {

			// Tick
			on_start_fn();

			// Render
			renderer->on_draw_begin();
			on_render_fn(0.0f);
			renderer->on_draw_frame(0.0f);
			renderer->on_draw_end();

			// Post Render
			window->swap_buffers();

			glfwPollEvents();
		}
	}

}

