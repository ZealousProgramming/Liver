#pragma once

#include "common.h"

class GLFWwindow;

namespace Liver {
	/**
		Abstraction for a desktop window.
	*/
	class Window {
		public:
			Window() = default;
			Window(const char* window_title, i16 window_width, i16 window_height) : native_window(nullptr), title(window_title), width(window_width), height(window_height) {}
			~Window() = default;
			
			/**
				Allows the Window to run of setup routines.
			*/
			bool initialize();

			/**
				Allows the process to clean up.
			*/
			void shutdown();

			/**
				Returns if there was a request to close the window.	

				@return Returns true if there was a request to close the window, otherwise false.
			*/
			bool should_close();

			/**
				Swaps the current buffers to draw the soon to be formerly backbuffer.		
			*/
			void swap_buffers();

			/**
				Returns the window's current title.

				@return Returns the window's current title.
			*/
			const char* get_title() { return title; }

			/**
				Returns the window's current width.

				@return Returns the window's current width.
			*/
			const i16 get_width() { return width; }

			/**
				Returns the window's current height.

				@return Returns the window's current height.
			*/
			const i16 get_height() { return height;  }

			/**
				Returns a pointer to the native window.
				[INTERNAL USE ONLY]

				@return Returns a pointer to the native GLFWwindow.
			*/
			GLFWwindow* get_native_window() const { return native_window; }

			/**
				Manually sets the size of the window frame.

				@param new_width The desired window frame width
				@param new_height The desired window frame height
			*/
			void set_size(const i16 new_width, const i16 new_height);

			/**
				Changes the title of the window.
	
				@param new_title The desired window title.
			*/
			void change_title(const char* new_title);
			
		private:
			/// Pointer to the native GLFWwindow
			GLFWwindow* native_window;
			/// The window title
			const char* title;
			/// The width of the window
			i16 width;
			/// The height of the window
			i16 height;
	};
}