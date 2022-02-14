#pragma once

#include "common.h"

class GLFWwindow;

namespace Liver {
	class Window;
	class Renderer;

	/**
		The core of a Sellas program.
	*/
	class Application {
		private:
			// GLFW Callback
			friend void framebuffer_resize_callback(GLFWwindow* window_inst, int width, int height);
		public:
			Application() = default;
			~Application() = default;
			Application(Application const&) = delete;
			Application& operator=(Application const&) = delete;

			/**
				Initializes the Application and any of it's modules.
				 
				@param window_title The initial title of the Application's window.
				@param window_width The initial width of the Application's window.
				@param window_height The initial height of the Application's window.

				@return Returns `true` if the application (and all of it's modules) sucessfully
					initialized, otherwise `false`.
			*/
			bool initialize(const char* window_title, const i16 window_width, const i16 window_height);

			/**
				Allows the process to clean up.
			*/
			void shutdown();

			/**
				Starts the Application's game-loop.
			*/
			void run();
			
			/**
				Links the user-defined lifecycle events to be called at their 
				respective stages in the lifecycle.

				@param enter_fn Function pointer to the function that will be called during the
					'enter' stage of the lifecycle.
				
				@param enter_fn Function pointer to the function that will be called during the
					'enter' stage of the lifecycle.
				
				@param enter_fn Function pointer to the function that will be called during the
					'enter' stage of the lifecycle.
				
				@param enter_fn Function pointer to the function that will be called during the
					'enter' stage of the lifecycle.
			*/
			void setup_lifecycle_events(std::function<void()> enter_fn, std::function<void()> exit_fn, std::function<void(f32)> tick_fn, std::function<void(f32)> render_fn);

			// Getters
			// --------
			/**
				Returns a reference to the Application singleton instance.

				@return Reference to the application instance.
			*/
			static Application& get_instance() { return *Application::instance; }
			
			/**
				Returns a reference to the Application's main window instance.

				@return Reference to window instance.
			*/
			Window& get_window() const { return *window.get(); }
		private:
			/// Singleton instance
			static Application* instance;
			/// Owned pointer to the Application's main window.
			Owned<Window> window;
			
			/// Function pointer to the function that will be called during the respective
			/// lifetime events.
			Func<void()> on_enter_fn;
			Func<void()> on_exit_fn;
			Func<void(f32)> on_tick_fn;
			Func<void(f32)> on_render_fn;

			/// Stores the time at the beginning of the previous frame.
			f32 last_frame_time;

	};
}