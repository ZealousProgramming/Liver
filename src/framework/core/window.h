#pragma once

#include "common.h"

class GLFWwindow;

/*
	Abstraction for a desktop window.

*/

namespace Sellas {
	class Window {
		public:
			Window() = default;
			Window(const char* window_title, i16 window_width, i16 window_height) : title(window_title), width(window_width), height(window_height) {}
			~Window() = default;
			

			bool initialize();
			void shutdown();

			bool should_close();
			void swap_buffers();

			const char* get_title() { return title; }
			const i16 get_width() { return width; }
			const i16 get_height() { return height;  }

			GLFWwindow* get_native_window() { return native_window;  }

			void set_size(const i16 new_width, const i16 new_height);
			void change_title(const char* new_title);
			
		private:
			GLFWwindow* native_window;
			const char* title;
			i16 width;
			i16 height;
	};
}