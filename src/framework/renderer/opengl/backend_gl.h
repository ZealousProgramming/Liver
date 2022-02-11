#pragma once

#include "../renderer_backend.h"

namespace Sellas {
	class ShaderProgramGL;
		
	class RendererGL : public RendererBackend {
		public:
			RendererGL() = default;
			~RendererGL() override;


			const bool initialize() override;

			void clear_color(const f32 r, const f32 g, const f32 b) override;
			void clear() override;
			void on_resize(const i16 x, const i16 y, const i16 new_width, const i16 new_height) override;

			void start_draw() override;
			void submit() override;

			void bind_shader() const override;

			void draw_indexed() override;

		private:
			void bind_vao(const u32 vao_handle) const;
		private:
			// NOTE(devon): Stored as a Ref as it'll be owned by the Resource Handler at a later date.
			Ref<ShaderProgramGL> default_shader_program;
			u32 vao;
			u32 vbo;
			u32 ebo;
	};
}