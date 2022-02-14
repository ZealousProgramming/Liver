#pragma once

#include "../core/common.h"

namespace Liver {
	/**
	* Public GSDK-agnostic interface for textures.
	*/
	class Texture {
		public:
			Texture() = default;
			~Texture() = default;
			Texture(const Texture&) = delete;
			Texture& operator=(const Texture&) = delete;
			
			virtual void initialize(const char* texture_path) = 0;
			virtual void shutdown() = 0;

			virtual void bind() const = 0;

			virtual const u32 get_id() const = 0;

			static Option<Ref<Texture>> create_texture();

	};
}