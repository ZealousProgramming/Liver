#include "texture_gl.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_ONLY_JPEG
#include "../../vendor/stb_image/stb_image.h"



namespace Sellas {
	TextureGL::~TextureGL() {
		shutdown();
	}
	
	/// <summary>
	/// </summary>
	/// <param name="texture_path">The relative path to the texture. 
	/// This is currently relative to the texture_gl directory. </param>
	// TODO(devon): Create a assets directory path to rebase the relative path.
	void TextureGL::initialize(const char* texture_path) {
		i32 width;
		i32 height;
		i32 channels;
		
		// Flip the image
		stbi_set_flip_vertically_on_load(true);

		byte* data = stbi_load(
			texture_path,
			&width,
			&height,
			&channels,
			0
		);

		if (!data) {
			std::cout << "[Sellas][Texture][GL] ERROR: Failed to load texture! \n\tPATH: " << texture_path << "\n";
			return;
		}
		
		// Generate Texture ID
		glGenTextures(1, &texture_id);

		// Bind Texture
		glBindTexture(GL_TEXTURE_2D, texture_id);

		// Texture Parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		// Generate Texture
		glTexImage2D(
			GL_TEXTURE_2D,		// Texture target
			0,					// Mipmap level
			GL_RGBA,			// Texture format of the resulting texture
			width,				// Width of the resulting texture
			height,				// Height of the resulting texture
			0,					// NOTE(devon): ALWAYS 0. This is legacy stuff.
			GL_RGBA,			// Format of the source image
			GL_UNSIGNED_BYTE,	// Data type of the source image
			reinterpret_cast<void*>(data)	// The actual image data)
		);

		// Generate Mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);


		stbi_image_free(data);
	}

	void TextureGL::shutdown() {
		glDeleteTextures(1, &texture_id);
	}

	void TextureGL::bind() const {
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

}