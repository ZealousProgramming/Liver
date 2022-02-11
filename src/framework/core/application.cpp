#include "application.h"

#include "window.h"
#include "../renderer/renderer.h"

#include <GLFW/glfw3.h>


namespace Sellas {
	bool Application::initialize(const char* window_title, const i16 window_width, const i16 window_height) {
		std::cout << "[Sellas][Application] Initializing..\n";

		if (on_enter_fn == nullptr) {
			std::cout << "[Sellas][Application] ERROR: Application Enter Function never assigned!\n";
			return false;
		}

		if (on_exit_fn == nullptr) {
			std::cout << "[Sellas][Application] ERROR: Application Exit Function never assigned!\n";
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

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = std::make_unique<Window>(window_title, window_width, window_height);
		//window = new Window(window_title, window_width, window_height);

		if (!window->initialize()) {
			std::cout << "[Sellas][Application] ERROR: Window failed to initialize!\n";
			return false;
		}


		if (!Renderer::initialize()) {
			std::cout << "[Sellas][Application] ERROR: Renderer failed to initialize!\n";
			return false;
		}
	
		
		Renderer::on_resize(0, 0, window_width, window_height);

		glfwSetFramebufferSizeCallback(window->get_native_window(), framebuffer_resize_callback);
		
		last_frame_time = 0.0f;

		return true;
	}

	void Application::shutdown() {
		Renderer::shutdown();

		window->shutdown();
		window.release();
		//delete window;

		std::cout << "[Sellas][Application] Shutting down..\n";
		glfwTerminate();
	}

	void Application::run() {
		
		on_enter_fn();

		while(!window->should_close()) {
			// Handle delta_time
			f32 current_time = static_cast<f32>(glfwGetTime());
			f32 delta_time = current_time - last_frame_time;
			last_frame_time = current_time;
			

			on_tick_fn(delta_time);

			// Render
			Renderer::start_draw();
			on_render_fn(delta_time);
			Renderer::end_draw();
			Renderer::submit();

			// Post Render
			window->swap_buffers();

			glfwPollEvents();
		}

		on_exit_fn();
	}

	void Application::setup_lifecycle_events(
		Func<void()> enter_fn, 
		Func<void()> exit_fn, 
		Func<void(f32)> tick_fn,
		Func<void(f32)> render_fn
	) {
		on_enter_fn = enter_fn;
		on_exit_fn = exit_fn;
		on_tick_fn = tick_fn;
		on_render_fn = render_fn;
	}
	
	
	void framebuffer_resize_callback(GLFWwindow* window_inst, int width, int height) {
		//window->set_size((i16)width, (i16)height);
		Sellas::Renderer::on_resize( 0, 0, width, height);
	}
}


