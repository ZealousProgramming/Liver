#pragma once

#include "../core/common.h"

namespace Sellas {
	class RendererBackend;

	class Renderer2D {
		public:
			Renderer2D() = default;
			~Renderer2D() = default;

			static bool initialize();
			static void shutdown();
			
			static void on_resize(const i16 x, const i16 y, const i16 width, const i16 height);

			static void draw_quad();

		private:
			static RendererBackend* backend;

	};
}