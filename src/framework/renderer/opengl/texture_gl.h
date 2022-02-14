#pragma once

#include "../../core/common.h"
#include "../texture.h"

namespace Liver {
	/**
	* Internal represenation of a texture for OpenGL
	*/
	class TextureGL : public Texture {
		public:
			TextureGL() = default;
			~TextureGL();
			TextureGL(const TextureGL&) = delete;
			TextureGL& operator=(const TextureGL&) = delete;

			
			void initialize(const char* texture_path) override;
			void shutdown() override;

			void bind() const override;

			const u32 get_id() const override { return texture_id; }
		private:
			u32 texture_id;
	};
}