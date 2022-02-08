#pragma once

#include "../renderer.h";

namespace Sellas {
	class GLRenderer : public Renderer {
		public:
			GLRenderer() = default;
			~GLRenderer() = default;

			bool initialize() const override;
			void shutdown() override;
			bool on_draw_frame(const f32 delta_time) const  override;
			void on_draw_begin() override;
			void on_draw_end() override;
			void on_resize(const i16 new_width, const i16 new_height) override;
		private:
	};
}