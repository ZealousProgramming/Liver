#pragma once

#include "common.h"

namespace Sellas {
	class Renderer;
	class Window;
	class GameInstance {
		public:
			GameInstance() = default;
			~GameInstance() = default;
			
			Window* GetMainWindow() { return window; }
		private:
			Window* window;
	};
}