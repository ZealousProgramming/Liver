#pragma once

#include "../core/common.h"

namespace Sellas {
	class RendererBackend {
		public: 
			enum class BackendAPI {
				OPEN_GL = 0,
				VULKAN = 1,
			};

		public:
			RendererBackend() = default;
			virtual ~RendererBackend() = default;

			virtual bool initialize() const = 0;

			virtual void clear_color(const f32 r, const f32 g, const f32 b) = 0;
			virtual void clear() = 0;
			virtual void on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) = 0;

			virtual void draw() = 0;
			virtual void draw_indexed() = 0;

			
			static BackendAPI GetBackend() { return backend; }
		private:
			static BackendAPI backend;
	};
}