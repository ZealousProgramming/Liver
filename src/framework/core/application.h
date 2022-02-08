#pragma once

#include "common.h"


/*
	The core of any Sellas program.

*/

namespace Sellas {
	class Window;
	class Renderer;

	class Application {
		public:
			Application() = default;
			~Application() = default;

			bool initialize(const char* window_title, const i16 window_width, const i16 window_height);
			void shutdown();
			void run();

			void (*on_start_fn)();
			void (*on_tick_fn)(f32 delta_time);
			void (*on_render_fn)(f32 delta_time);

			// Getters
			Window* get_window() { return window; }
		private:
			Window* window = nullptr;
			Renderer* renderer = nullptr;
	};
}