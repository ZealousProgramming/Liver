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

		private:
			u32 handle;
	};
}