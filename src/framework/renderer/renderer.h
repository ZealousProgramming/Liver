#pragma once

#include "../core/common.h"
#include "renderer_backend.h"

namespace Sellas {
	/**
	* Platform agnostic interface for the renderer
	* 
	* Renderer is an interface to leverage a platform agnostic 
	* API for the framework to use internally. Renderer is not 
	* meant for the user to use directly in their rendering code. 
	* For rendering functionality see @renderer2d.h for 2D related 
	* functionality.
	*
	*/
	class Renderer {
		public:
			Renderer() = default;
			~Renderer() = default;
			Renderer(Renderer const&) = delete;
			Renderer& operator=(Renderer const&) = delete;

			static bool initialize();
			static void shutdown();

			static void start_draw();
			static void end_draw();

			static void submit();
			
			static void on_resize(const i16 x, const i16 y, const i16 width, const i16 height);
			
			static RendererBackend::BackendAPI GetBackend() { return RendererBackend::GetBackend(); }
		private:
			static constexpr f32 clear_r = 0.91373f;// 0.87451f;
			static constexpr f32 clear_g = 0.6f;
			static constexpr f32 clear_b = 0.51765f;
	};
}
