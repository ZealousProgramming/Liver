#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace Sellas {

	bool Window::initialize() {
		native_window = glfwCreateWindow((int)width, (int)height, title, NULL, NULL);

		if(!native_window) {
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(native_window);

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
			std::cout << "[Sellas][Window]: GLAD initialization failed" << "\n";
			return false;
		}

		return true;
	}

	void Window::shutdown() {

		glfwDestroyWindow(native_window);
	}

	bool Window::should_close() {
		return glfwWindowShouldClose(native_window);
	}

	void Window::swap_buffers() {
		glfwSwapBuffers(native_window);
	}
	
	void Window::set_size(const i16 new_width, const i16 new_height) {
		width = new_width;
		height = new_height;
	}

	void Window::change_title(const char* new_title) {
		title = new_title;

		// TODO(devon): Update the actual window frame
	}

}