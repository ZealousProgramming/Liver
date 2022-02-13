#pragma once

#include "common.h"
#include "math/math.h"

#include <GLFW/glfw3.h>

namespace Sellas {
	enum class InputState {
		NEUTRAL = 3,
		PRESSED = GLFW_PRESS,
		RELEASED = GLFW_RELEASE,
		DOWN = GLFW_REPEAT
	};

	enum class MouseButton {
		MOUSE_BUTTON_LEFT = 0,
		MOUSE_BUTTON_RIGHT = 1,
		MOUSE_BUTTON_MIDDLE = 2,
		MOUSE_BUTTON_4 = 3,
		MOUSE_BUTTON_5 = 4,
		MOUSE_BUTTON_6 = 5,
		MOUSE_BUTTON_7 = 6,
		MOUSE_BUTTON_8 = 7,
	};

	enum class Key {
        KEY_UNKNOWN = -1,
		KEY_SPACE = 32,
		KEY_APOSTROPHE = 39, // '
		KEY_COMMA = 44, // ,
		KEY_MINUS = 45, // -
		KEY_PERIOD = 46, // .
		KEY_SLASH = 47, // /
		KEY_0 = 48,
		KEY_1 = 49,
		KEY_2 = 50,
		KEY_3 = 51,
		KEY_4 = 52,
		KEY_5 = 53,
		KEY_6 = 54,
		KEY_7 = 55,
		KEY_8 = 56,
		KEY_9 = 57,
		KEY_SEMICOLON = 59, // ;
		KEY_EQUAL = 61, // =
		KEY_A = 65,
		KEY_B = 66,
		KEY_C = 67,
		KEY_D = 68,
		KEY_E = 69,
		KEY_F = 70,
		KEY_G = 71,
		KEY_H = 72,
		KEY_I = 73,
		KEY_J = 74,
		KEY_K = 75,
		KEY_L = 76,
		KEY_M = 77,
		KEY_N = 78,
		KEY_O = 79,
		KEY_P = 80,
		KEY_Q = 81,
		KEY_R = 82,
		KEY_S = 83,
		KEY_T = 84,
		KEY_U = 85,
		KEY_V = 86,
		KEY_W = 87,
		KEY_X = 88,
		KEY_Y = 89,
		KEY_Z = 90,
		KEY_LEFTBRACKET = 91, // [
		KEY_BACKSLASH = 92, // \    
		KEY_RIGHTBRACKET     = 93, // ]
		KEY_BACKTICK = 96, // `
		KEY_WORLD1 = 161, //NON-US #1
		KEY_WORLD2 = 162, //NON-US #2
		KEY_ESCAPE = 256,
		KEY_ENTER = 257,
		KEY_TAB = 258,
		KEY_BACKSPACE = 259,
		KEY_INSERT = 260,
		KEY_DELETE = 261,
		KEY_RIGHT = 262,
		KEY_LEFT = 263,
		KEY_DOWN = 264,
		KEY_UP = 265,
		KEY_PAGEUP = 266,
		KEY_PAGEDOWN = 267,
		KEY_HOME = 268,
		KEY_END = 269,
		KEY_CAPSLOCK = 280,
		KEY_SCROLLLOCK = 281,
		KEY_NUMLOCK = 282,
		KEY_PRINTSCREEN = 283,
		KEY_PAUSE = 284,
		KEY_F1 = 290,
		KEY_F2 = 291,
		KEY_F3 = 292,
		KEY_F4 = 293,
		KEY_F5 = 294,
		KEY_F6 = 295,
		KEY_F7 = 296,
		KEY_F8 = 297,
		KEY_F9 = 298,
		KEY_F10 = 299,
		KEY_F11 = 300,
		KEY_F12 = 301,
		KEY_F13 = 302,
		KEY_F14 = 303,
		KEY_F15 = 304,
		KEY_F16 = 305,
		KEY_F17 = 306,
		KEY_F18 = 307,
		KEY_F19 = 308,
		KEY_F20 = 309,
		KEY_F21 = 310,
		KEY_F22 = 311,
		KEY_F23 = 312,
		KEY_F24 = 313,
		KEY_F25 = 314,
		KEY_KEYPAD0 = 320,
		KEY_KEYPAD1 = 321,
		KEY_KEYPAD2 = 322,
		KEY_KEYPAD3 = 323,
		KEY_KEYPAD4 = 324,
		KEY_KEYPAD5 = 325,
		KEY_KEYPAD6 = 326,
		KEY_KEYPAD7 = 327,
		KEY_KEYPAD8 = 328,
		KEY_KEYPAD9 = 329,
		KEY_KEYPADDECIMAL = 330,
		KEY_KEYPADDIVIDE = 331,
		KEY_KEYPADMULTIPLY = 332,
		KEY_KEYPADSUBTRACT = 333,
		KEY_KEYPADADD = 334,
		KEY_KEYPADENTER = 335,
		KEY_KEYPADEQUAL = 336,
		KEY_LEFTSHIFT = 340,
		KEY_LEFTCONTROL = 341,
		KEY_LEFTALT = 342,
		KEY_LEFTSUPER = 343,
		KEY_RIGHTSHIFT = 344,
		KEY_RIGHTCONTROL = 345,
		KEY_RIGHTALT = 346,
		KEY_RIGHTSUPER = 347,
		KEY_MENU = 348,
	};

	class Input {
		private:
			friend void mouse_position_callback(GLFWwindow* window_inst, f64 x, f64 y);
			friend void mouse_button_callback(GLFWwindow* window_inst, i32 button, i32 action, i32 mods);
			friend void keyboard_callback(GLFWwindow* window_inst, i32 key, i32 scancode, i32 action, i32 mods);
		public:
			static void initialize();
			static const bool is_key_pressed(Key keycode);

			static const glm::vec2 get_mouse_position() { return Input::mouse_position; }
		private:
			static glm::vec2 mouse_position;
			static std::unordered_map<Key, InputState> key_map;
	};

}