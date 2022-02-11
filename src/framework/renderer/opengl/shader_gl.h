#pragma once

#include "../../core/common.h"

namespace Sellas {
	class ShaderGL {
		public:
			ShaderGL() = default;
			~ShaderGL() = default;

			void initialize(const u32 type);
			void shutdown();

			void source();
			const bool compile();

			u32 get_handle() const { return handle; }

		private:
			u32 handle;
			u32 shader_type;

			const char* shader_type_to_string(const u32 type) const;
	};
}