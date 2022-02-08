#pragma once

#include "../core/common.h";

namespace Sellas {
	class Renderer {
		public:
			Renderer() = default;
			~Renderer() = default;

			virtual bool initialize() const = 0;
			virtual void shutdown() = 0;
			virtual bool on_draw_frame(const f32 delta_time) const = 0;
			virtual void on_draw_begin() = 0;
			virtual void on_draw_end() = 0;
			virtual void on_resize(const i16 new_width, const i16 new_height) = 0;
	};
}