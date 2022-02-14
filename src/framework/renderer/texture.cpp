#include "texture.h"

#include "renderer_backend.h"
#include "opengl/texture_gl.h"

namespace Liver {

	Option<Ref<Texture>> Texture::create_texture() {
		switch (RendererBackend::GetBackend()) {
			case RendererBackend::BackendAPI::OPEN_GL: {
				return std::make_shared<TextureGL>();
			}

			default:
				return std::nullopt;
		}
	}
}