#pragma once

#include "../../core/common.h"

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
			
			// Uniform Setters
			void set_bool(const char* uniform_name, const bool value) const;
			void set_int(const char* uniform_name, const i32 value) const;
			void set_float(const char* uniform_name, const f32 value) const;

		private:
			u32 handle;
	};
}