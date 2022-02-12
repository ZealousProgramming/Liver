#pragma once

#include "../../core/common.h"
#include "../../core/math/math.h"

namespace Sellas {

	using ShaderHandle = u32;

	class ShaderProgramGL {
		public:
			ShaderProgramGL() = default;
			~ShaderProgramGL() = default;
			ShaderProgramGL(ShaderProgramGL const&) = delete;
			ShaderProgramGL& operator=(ShaderProgramGL const&) = delete;

			void initialize();
			void shutdown();

			void bind();
			void link();
			void attach(const ShaderHandle shader_handle);

			const u32 get_uniform_location(const char* uniform_name) const;
			
			// Uniform Setters
			void set_bool(const char* uniform_name, const bool value) const;
			void set_int(const char* uniform_name, const i32 value) const;
			void set_float(const char* uniform_name, const f32 value) const;
			void set_matrix4(const char* uniform_name, const glm::mat4& value) const;

		private:
			u32 handle;
	};
}