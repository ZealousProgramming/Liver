#pragma once

#include "../renderer_backend.h"

namespace Sellas {
	class ShaderProgramGL;
		
	class RendererGL : public RendererBackend {
		public:
			RendererGL() = default;
			~RendererGL() override;


			bool initialize() const override;

			void clear_color(const f32 r, const f32 g, const f32 b) override;
			void clear() override;
			void on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) override;

			void draw() override;
			void draw_indexed() override;
		private:
			// NOTE(devon): Stored as a Ref as it'll be owned by the Resource Handler at a later date.
			Ref<ShaderProgramGL> default_shader_program;
	};
}