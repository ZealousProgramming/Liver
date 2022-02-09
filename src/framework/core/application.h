#pragma once

#include "common.h"

/*
	The core of any Sellas program.

*/
class GLFWwindow;

namespace Sellas {
	class Window;
	class Renderer;

	class Application {
		private:
			friend void framebuffer_resize_callback(GLFWwindow* window_inst, int width, int height);

		public:
			Application() = default;
			~Application() = default;

			bool initialize(const char* window_title, const i16 window_width, const i16 window_height);
			void shutdown();
			void run();

			void setup_lifecycle_events(std::function<void()> enter_fn, std::function<void()> exit_fn, std::function<void(f32)> tick_fn, std::function<void(f32)> render_fn);

			// Getters
			Window* get_window() { return window; }
		private:
			Window* window = nullptr;
			
			// Lifecycle event callbacks
			std::function<void()> on_enter_fn;
			std::function<void()> on_exit_fn;
			std::function<void(f32)> on_tick_fn;
			std::function<void(f32)> on_render_fn;

			f32 last_frame_time;

	};
}