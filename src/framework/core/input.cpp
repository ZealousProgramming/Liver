#include "input.h"

#include "application.h"
#include "window.h"

namespace Liver {
	// --- Forward Declarations
	void mouse_position_callback(GLFWwindow* window_inst, f64 x, f64 y);
	void mouse_button_callback(GLFWwindow* window_inst, i32 button, i32 action, i32 mods);
	void keyboard_callback(GLFWwindow* window_inst, i32 key, i32 scancode, i32 action, i32 mods);

	// --- Static Declarations
	std::unordered_map<Key, InputState> Input::key_map;
	glm::vec2 Input::mouse_position = glm::vec2(0.0f, 0.0f);

	void Input::initialize() {
		auto native_window = Application::get_instance().get_window().get_native_window();

		glfwSetCursorPosCallback(native_window, mouse_position_callback);
		glfwSetMouseButtonCallback(native_window, mouse_button_callback);
		glfwSetKeyCallback(native_window, keyboard_callback);

		// Key_Map
		key_map.insert({ Key::KEY_UNKNOWN, InputState::NEUTRAL });
		key_map.insert({Key::KEY_SPACE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_APOSTROPHE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_COMMA, InputState::NEUTRAL });
		key_map.insert({Key::KEY_MINUS, InputState::NEUTRAL });
		key_map.insert({Key::KEY_PERIOD, InputState::NEUTRAL });
		key_map.insert({Key::KEY_SLASH, InputState::NEUTRAL });
		key_map.insert({Key::KEY_0, InputState::NEUTRAL });
		key_map.insert({Key::KEY_1, InputState::NEUTRAL });
		key_map.insert({Key::KEY_2, InputState::NEUTRAL });
		key_map.insert({Key::KEY_3, InputState::NEUTRAL });
		key_map.insert({Key::KEY_4, InputState::NEUTRAL });
		key_map.insert({Key::KEY_5, InputState::NEUTRAL });
		key_map.insert({Key::KEY_6, InputState::NEUTRAL });
		key_map.insert({Key::KEY_7, InputState::NEUTRAL });
		key_map.insert({Key::KEY_8, InputState::NEUTRAL });
		key_map.insert({Key::KEY_9, InputState::NEUTRAL });
		key_map.insert({Key::KEY_SEMICOLON, InputState::NEUTRAL });
		key_map.insert({Key::KEY_EQUAL, InputState::NEUTRAL });
		key_map.insert({Key::KEY_A, InputState::NEUTRAL });
		key_map.insert({Key::KEY_B, InputState::NEUTRAL });
		key_map.insert({Key::KEY_C, InputState::NEUTRAL });
		key_map.insert({Key::KEY_D, InputState::NEUTRAL });
		key_map.insert({Key::KEY_E, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F, InputState::NEUTRAL });
		key_map.insert({Key::KEY_G, InputState::NEUTRAL });
		key_map.insert({Key::KEY_H, InputState::NEUTRAL });
		key_map.insert({Key::KEY_I, InputState::NEUTRAL });
		key_map.insert({Key::KEY_J, InputState::NEUTRAL });
		key_map.insert({Key::KEY_K, InputState::NEUTRAL });
		key_map.insert({Key::KEY_L, InputState::NEUTRAL });
		key_map.insert({Key::KEY_M, InputState::NEUTRAL });
		key_map.insert({Key::KEY_N, InputState::NEUTRAL });
		key_map.insert({Key::KEY_O, InputState::NEUTRAL });
		key_map.insert({Key::KEY_P, InputState::NEUTRAL });
		key_map.insert({Key::KEY_Q, InputState::NEUTRAL });
		key_map.insert({Key::KEY_R, InputState::NEUTRAL });
		key_map.insert({Key::KEY_S, InputState::NEUTRAL });
		key_map.insert({Key::KEY_T, InputState::NEUTRAL });
		key_map.insert({Key::KEY_U, InputState::NEUTRAL });
		key_map.insert({Key::KEY_V, InputState::NEUTRAL });
		key_map.insert({Key::KEY_W, InputState::NEUTRAL });
		key_map.insert({Key::KEY_X, InputState::NEUTRAL });
		key_map.insert({Key::KEY_Y, InputState::NEUTRAL });
		key_map.insert({Key::KEY_Z, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFTBRACKET, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHTBRACKET, InputState::NEUTRAL });
		key_map.insert({Key::KEY_BACKSLASH, InputState::NEUTRAL });
		key_map.insert({Key::KEY_BACKTICK, InputState::NEUTRAL });
		key_map.insert({Key::KEY_WORLD1, InputState::NEUTRAL });
		key_map.insert({Key::KEY_WORLD2, InputState::NEUTRAL });
		key_map.insert({Key::KEY_ESCAPE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_ENTER, InputState::NEUTRAL });
		key_map.insert({Key::KEY_TAB, InputState::NEUTRAL });
		key_map.insert({Key::KEY_BACKSPACE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_INSERT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_DELETE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_DOWN, InputState::NEUTRAL });
		key_map.insert({Key::KEY_UP, InputState::NEUTRAL });
		key_map.insert({Key::KEY_PAGEUP, InputState::NEUTRAL });
		key_map.insert({Key::KEY_PAGEDOWN, InputState::NEUTRAL });
		key_map.insert({Key::KEY_HOME, InputState::NEUTRAL });
		key_map.insert({Key::KEY_END, InputState::NEUTRAL });
		key_map.insert({Key::KEY_CAPSLOCK, InputState::NEUTRAL });
		key_map.insert({Key::KEY_SCROLLLOCK, InputState::NEUTRAL });
		key_map.insert({Key::KEY_NUMLOCK, InputState::NEUTRAL });
		key_map.insert({Key::KEY_PRINTSCREEN, InputState::NEUTRAL });
		key_map.insert({Key::KEY_PAUSE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F1, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F2, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F3, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F4, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F5, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F6, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F7, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F8, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F9, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F10, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F11, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F12, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F13, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F14, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F15, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F16, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F17, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F18, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F19, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F20, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F21, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F22, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F23, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F24, InputState::NEUTRAL });
		key_map.insert({Key::KEY_F25, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD0, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD1, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD2, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD3, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD4, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD5, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD6, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD7, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD8, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPAD9, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADDECIMAL, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADDIVIDE, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADMULTIPLY, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADSUBTRACT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADADD, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADENTER, InputState::NEUTRAL });
		key_map.insert({Key::KEY_KEYPADEQUAL, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFTSHIFT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFTCONTROL, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFTALT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_LEFTSUPER, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHTSHIFT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHTCONTROL, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHTALT, InputState::NEUTRAL });
		key_map.insert({Key::KEY_RIGHTSUPER, InputState::NEUTRAL });
		key_map.insert({Key::KEY_MENU, InputState::NEUTRAL });
	}

	const bool Input::is_key_pressed(const Key keycode) {
		auto key = key_map.find(keycode);

		if (key == key_map.end()) return false;
		
		auto state = key_map[keycode];
		return  state == InputState::PRESSED || state == InputState::DOWN;
	}

	void mouse_position_callback(GLFWwindow* window_inst, f64 x, f64 y)
	{
		//std::cout << "[Liver][Input][Mouse Position] x: " << x << ", y: " << y << "\n";
		Input::mouse_position.x = x;
		Input::mouse_position.y = y;
	}

	void mouse_button_callback(GLFWwindow* window_inst, i32 button, i32 action, i32 mods) {
		//std::cout << "[Liver][Input][Mouse Button] button: " << button << " , action: " << action << ", mods: " << mods << "\n";
		// TODO(devon): Set the mouse button state
	}
	
	void keyboard_callback(GLFWwindow* window_inst, i32 key, i32 scancode, i32 action, i32 mods) {
		//std::cout << "[Liver][Input][Keyboard] key: " << key <<", scancode: " << scancode << " , action: " << action << ", mods: " << mods << "\n";
		
		auto converted_key = (Key)key;
		if (Input::key_map.contains(converted_key)) {
			auto converted_action = (InputState)action;
			Input::key_map.insert_or_assign(converted_key, converted_action);
			
			if (converted_action == InputState::RELEASED) {
				// TODO(devon): Add to the released map
			}
		}
	}
}