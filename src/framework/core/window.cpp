#include "window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace Sellas {

	bool Window::initialize() {
		window_inst = glfwCreateWindow((int)width, (int)height, title, NULL, NULL);

		if(!window_inst) {
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window_inst);

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
			std::cout << "[Sellas][Window]: GLAD initialization failed" << "\n";
			return false;
		}

		return true;
	}

	void Window::shutdown() {

		glfwDestroyWindow(window_inst);
	}

	bool Window::should_close() {
		return glfwWindowShouldClose(window_inst);
	}

	void Window::swap_buffers() {
		glfwSwapBuffers(window_inst);
	}
	
	void Window::change_title(const char* new_title) {
		title = new_title;

		// TODO(devon): Update the actual window frame
	}
}