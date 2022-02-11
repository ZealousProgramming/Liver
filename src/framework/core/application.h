#pragma once

#include "common.h"
//#include "window.h"

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
			Application(Application const&) = delete;
			Application& operator=(Application const&) = delete;

			bool initialize(const char* window_title, const i16 window_width, const i16 window_height);
			void shutdown();
			void run();

			void setup_lifecycle_events(std::function<void()> enter_fn, std::function<void()> exit_fn, std::function<void(f32)> tick_fn, std::function<void(f32)> render_fn);

			// Getters
			Window& get_window() const { return *window.get(); }
		private:
			//Window* window = nullptr;
			Owned<Window> window;
			
			// Lifecycle event callbacks
			Func<void()> on_enter_fn;
			Func<void()> on_exit_fn;
			Func<void(f32)> on_tick_fn;
			Func<void(f32)> on_render_fn;

			f32 last_frame_time;

	};
}