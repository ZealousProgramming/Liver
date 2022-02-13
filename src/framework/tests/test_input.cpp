#include "gtest/gtest.h"

#include <GLFW/glfw3.h>
#include "../core/input.h"


TEST(input_testing, input_state_sanity) {
	EXPECT_EQ((int)Sellas::InputState::PRESSED, GLFW_PRESS);
	EXPECT_NE((int)Sellas::InputState::PRESSED, 5);
	EXPECT_EQ((int)Sellas::InputState::RELEASED, GLFW_RELEASE);
	EXPECT_EQ((int)Sellas::InputState::DOWN, GLFW_REPEAT);
}

TEST(input_testing, mouse_button_sanity) {
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_LEFT, GLFW_MOUSE_BUTTON_LEFT);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_RIGHT, GLFW_MOUSE_BUTTON_RIGHT);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_MIDDLE, GLFW_MOUSE_BUTTON_MIDDLE);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_4, GLFW_MOUSE_BUTTON_4);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_5, GLFW_MOUSE_BUTTON_5);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_6, GLFW_MOUSE_BUTTON_6);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_7, GLFW_MOUSE_BUTTON_7);
	EXPECT_EQ((int)Sellas::MouseButton::MOUSE_BUTTON_8, GLFW_MOUSE_BUTTON_8);
}

TEST(input_testing, key_sanity) {
	EXPECT_EQ((int)Sellas::Key::KEY_UNKNOWN				,GLFW_KEY_UNKNOWN);
	EXPECT_EQ((int)Sellas::Key::KEY_SPACE				,GLFW_KEY_SPACE);
	EXPECT_EQ((int)Sellas::Key::KEY_APOSTROPHE			,GLFW_KEY_APOSTROPHE); // '
	EXPECT_EQ((int)Sellas::Key::KEY_COMMA				,GLFW_KEY_COMMA); // ,
	EXPECT_EQ((int)Sellas::Key::KEY_MINUS				,GLFW_KEY_MINUS); // -
	EXPECT_EQ((int)Sellas::Key::KEY_PERIOD				,GLFW_KEY_PERIOD); // .
	EXPECT_EQ((int)Sellas::Key::KEY_SLASH				,GLFW_KEY_SLASH); // /
	EXPECT_EQ((int)Sellas::Key::KEY_0					,GLFW_KEY_0);
	EXPECT_EQ((int)Sellas::Key::KEY_1					,GLFW_KEY_1);
	EXPECT_EQ((int)Sellas::Key::KEY_2					,GLFW_KEY_2);
	EXPECT_EQ((int)Sellas::Key::KEY_3					,GLFW_KEY_3);
	EXPECT_EQ((int)Sellas::Key::KEY_4					,GLFW_KEY_4);
	EXPECT_EQ((int)Sellas::Key::KEY_5					,GLFW_KEY_5);
	EXPECT_EQ((int)Sellas::Key::KEY_6					,GLFW_KEY_6);
	EXPECT_EQ((int)Sellas::Key::KEY_7					,GLFW_KEY_7);
	EXPECT_EQ((int)Sellas::Key::KEY_8					,GLFW_KEY_8);
	EXPECT_EQ((int)Sellas::Key::KEY_9					,GLFW_KEY_9);
	EXPECT_EQ((int)Sellas::Key::KEY_SEMICOLON			,GLFW_KEY_SEMICOLON); // ;
	EXPECT_EQ((int)Sellas::Key::KEY_EQUAL				,GLFW_KEY_EQUAL); // =
	EXPECT_EQ((int)Sellas::Key::KEY_A					,GLFW_KEY_A);
	EXPECT_EQ((int)Sellas::Key::KEY_B					,GLFW_KEY_B);
	EXPECT_EQ((int)Sellas::Key::KEY_C					,GLFW_KEY_C);
	EXPECT_EQ((int)Sellas::Key::KEY_D					,GLFW_KEY_D);
	EXPECT_EQ((int)Sellas::Key::KEY_E					,GLFW_KEY_E);
	EXPECT_EQ((int)Sellas::Key::KEY_F					,GLFW_KEY_F);
	EXPECT_EQ((int)Sellas::Key::KEY_G					,GLFW_KEY_G);
	EXPECT_EQ((int)Sellas::Key::KEY_H					,GLFW_KEY_H);
	EXPECT_EQ((int)Sellas::Key::KEY_I					,GLFW_KEY_I);
	EXPECT_EQ((int)Sellas::Key::KEY_J					,GLFW_KEY_J);
	EXPECT_EQ((int)Sellas::Key::KEY_K					,GLFW_KEY_K);
	EXPECT_EQ((int)Sellas::Key::KEY_L					,GLFW_KEY_L);
	EXPECT_EQ((int)Sellas::Key::KEY_M					,GLFW_KEY_M);
	EXPECT_EQ((int)Sellas::Key::KEY_N					,GLFW_KEY_N);
	EXPECT_EQ((int)Sellas::Key::KEY_O					,GLFW_KEY_O);
	EXPECT_EQ((int)Sellas::Key::KEY_P					,GLFW_KEY_P);
	EXPECT_EQ((int)Sellas::Key::KEY_Q					,GLFW_KEY_Q);
	EXPECT_EQ((int)Sellas::Key::KEY_R					,GLFW_KEY_R);
	EXPECT_EQ((int)Sellas::Key::KEY_S					,GLFW_KEY_S);
	EXPECT_EQ((int)Sellas::Key::KEY_T					,GLFW_KEY_T);
	EXPECT_EQ((int)Sellas::Key::KEY_U					,GLFW_KEY_U);
	EXPECT_EQ((int)Sellas::Key::KEY_V					,GLFW_KEY_V);
	EXPECT_EQ((int)Sellas::Key::KEY_W					,GLFW_KEY_W);
	EXPECT_EQ((int)Sellas::Key::KEY_X					,GLFW_KEY_X);
	EXPECT_EQ((int)Sellas::Key::KEY_Y					,GLFW_KEY_Y);
	EXPECT_EQ((int)Sellas::Key::KEY_Z					,GLFW_KEY_Z);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFTBRACKET			,GLFW_KEY_LEFT_BRACKET); // [
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHTBRACKET		,GLFW_KEY_RIGHT_BRACKET); // [
	EXPECT_EQ((int)Sellas::Key::KEY_BACKSLASH			,GLFW_KEY_BACKSLASH); // \    KEY_RIGHTBRACKET     = 93, // ]
	EXPECT_EQ((int)Sellas::Key::KEY_BACKTICK			,GLFW_KEY_GRAVE_ACCENT); // `
	EXPECT_EQ((int)Sellas::Key::KEY_WORLD1				,GLFW_KEY_WORLD_1); //NON-US #1
	EXPECT_EQ((int)Sellas::Key::KEY_WORLD2				,GLFW_KEY_WORLD_2); //NON-US #2
	EXPECT_EQ((int)Sellas::Key::KEY_ESCAPE				,GLFW_KEY_ESCAPE);
	EXPECT_EQ((int)Sellas::Key::KEY_ENTER				,GLFW_KEY_ENTER);
	EXPECT_EQ((int)Sellas::Key::KEY_TAB					,GLFW_KEY_TAB);
	EXPECT_EQ((int)Sellas::Key::KEY_BACKSPACE			,GLFW_KEY_BACKSPACE);
	EXPECT_EQ((int)Sellas::Key::KEY_INSERT				,GLFW_KEY_INSERT);
	EXPECT_EQ((int)Sellas::Key::KEY_DELETE				,GLFW_KEY_DELETE);
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHT				,GLFW_KEY_RIGHT);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFT				,GLFW_KEY_LEFT);
	EXPECT_EQ((int)Sellas::Key::KEY_DOWN				,GLFW_KEY_DOWN);
	EXPECT_EQ((int)Sellas::Key::KEY_UP					,GLFW_KEY_UP);
	EXPECT_EQ((int)Sellas::Key::KEY_PAGEUP				,GLFW_KEY_PAGE_UP);
	EXPECT_EQ((int)Sellas::Key::KEY_PAGEDOWN			,GLFW_KEY_PAGE_DOWN);
	EXPECT_EQ((int)Sellas::Key::KEY_HOME				,GLFW_KEY_HOME);
	EXPECT_EQ((int)Sellas::Key::KEY_END					,GLFW_KEY_END);
	EXPECT_EQ((int)Sellas::Key::KEY_CAPSLOCK			,GLFW_KEY_CAPS_LOCK);
	EXPECT_EQ((int)Sellas::Key::KEY_SCROLLLOCK			,GLFW_KEY_SCROLL_LOCK);
	EXPECT_EQ((int)Sellas::Key::KEY_NUMLOCK				,GLFW_KEY_NUM_LOCK);
	EXPECT_EQ((int)Sellas::Key::KEY_PRINTSCREEN			,GLFW_KEY_PRINT_SCREEN);
	EXPECT_EQ((int)Sellas::Key::KEY_PAUSE				,GLFW_KEY_PAUSE);
	EXPECT_EQ((int)Sellas::Key::KEY_F1					,GLFW_KEY_F1);
	EXPECT_EQ((int)Sellas::Key::KEY_F2					,GLFW_KEY_F2);
	EXPECT_EQ((int)Sellas::Key::KEY_F3					,GLFW_KEY_F3);
	EXPECT_EQ((int)Sellas::Key::KEY_F4					,GLFW_KEY_F4);
	EXPECT_EQ((int)Sellas::Key::KEY_F5					,GLFW_KEY_F5);
	EXPECT_EQ((int)Sellas::Key::KEY_F6					,GLFW_KEY_F6);
	EXPECT_EQ((int)Sellas::Key::KEY_F7					,GLFW_KEY_F7);
	EXPECT_EQ((int)Sellas::Key::KEY_F8					,GLFW_KEY_F8);
	EXPECT_EQ((int)Sellas::Key::KEY_F9					,GLFW_KEY_F9);
	EXPECT_EQ((int)Sellas::Key::KEY_F10					,GLFW_KEY_F10);
	EXPECT_EQ((int)Sellas::Key::KEY_F11					,GLFW_KEY_F11);
	EXPECT_EQ((int)Sellas::Key::KEY_F12					,GLFW_KEY_F12);
	EXPECT_EQ((int)Sellas::Key::KEY_F13					,GLFW_KEY_F13);
	EXPECT_EQ((int)Sellas::Key::KEY_F14					,GLFW_KEY_F14);
	EXPECT_EQ((int)Sellas::Key::KEY_F15					,GLFW_KEY_F15);
	EXPECT_EQ((int)Sellas::Key::KEY_F16					,GLFW_KEY_F16);
	EXPECT_EQ((int)Sellas::Key::KEY_F17					,GLFW_KEY_F17);
	EXPECT_EQ((int)Sellas::Key::KEY_F18					,GLFW_KEY_F18);
	EXPECT_EQ((int)Sellas::Key::KEY_F19					,GLFW_KEY_F19);
	EXPECT_EQ((int)Sellas::Key::KEY_F20					,GLFW_KEY_F20);
	EXPECT_EQ((int)Sellas::Key::KEY_F21					,GLFW_KEY_F21);
	EXPECT_EQ((int)Sellas::Key::KEY_F22					,GLFW_KEY_F22);
	EXPECT_EQ((int)Sellas::Key::KEY_F23					,GLFW_KEY_F23);
	EXPECT_EQ((int)Sellas::Key::KEY_F24					,GLFW_KEY_F24);
	EXPECT_EQ((int)Sellas::Key::KEY_F25					,GLFW_KEY_F25);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD0				,GLFW_KEY_KP_0);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD1				,GLFW_KEY_KP_1);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD2				,GLFW_KEY_KP_2);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD3				,GLFW_KEY_KP_3);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD4				,GLFW_KEY_KP_4);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD5				,GLFW_KEY_KP_5);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD6				,GLFW_KEY_KP_6);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD7				,GLFW_KEY_KP_7);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD8				,GLFW_KEY_KP_8);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPAD9				,GLFW_KEY_KP_9);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADDECIMAL		,GLFW_KEY_KP_DECIMAL);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADDIVIDE		,GLFW_KEY_KP_DIVIDE);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADMULTIPLY		,GLFW_KEY_KP_MULTIPLY);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADSUBTRACT		,GLFW_KEY_KP_SUBTRACT);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADADD			,GLFW_KEY_KP_ADD);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADENTER			,GLFW_KEY_KP_ENTER);
	EXPECT_EQ((int)Sellas::Key::KEY_KEYPADEQUAL			,GLFW_KEY_KP_EQUAL);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFTSHIFT			,GLFW_KEY_LEFT_SHIFT);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFTCONTROL			,GLFW_KEY_LEFT_CONTROL);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFTALT				,GLFW_KEY_LEFT_ALT);
	EXPECT_EQ((int)Sellas::Key::KEY_LEFTSUPER			,GLFW_KEY_LEFT_SUPER);
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHTSHIFT			,GLFW_KEY_RIGHT_SHIFT);
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHTCONTROL		,GLFW_KEY_RIGHT_CONTROL);
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHTALT			,GLFW_KEY_RIGHT_ALT);
	EXPECT_EQ((int)Sellas::Key::KEY_RIGHTSUPER			,GLFW_KEY_RIGHT_SUPER);
	EXPECT_EQ((int)Sellas::Key::KEY_MENU				,GLFW_KEY_MENU);
}
