#pragma once

#include "../core/common.h"
#include "../../core/camera.h"

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

			virtual const bool initialize() = 0;

			virtual void clear_color(const f32 r, const f32 g, const f32 b) = 0;
			virtual void clear() = 0;
			virtual void on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) = 0;
			
			virtual void start_draw(const Camera& current_camera) = 0;
			virtual void submit() = 0;

			virtual void bind_shader() const = 0;

			virtual void draw_indexed() = 0;

			static void set_api(BackendAPI api) { RendererBackend::backend = api; }
			static BackendAPI GetBackend() { return backend; }
		private:
			static BackendAPI backend;
	};
}