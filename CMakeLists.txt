# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.16)

project ("SellasSandbox" LANGUAGES CXX C)
set(cmake_cxx_standard 20)

# Allow for all warnings
add_compile_options(-DWall )

# Append all project includes
set(includes
	# Framework
	"src/framework/sellas.h"
	# --- Core
	"src/framework/core/common.h"
	"src/framework/core/window.h"
	"src/framework/core/application.h"
	# --- Renderer
	"src/framework/renderer/renderer.h" 
	"src/framework/renderer/renderer_2d.h" 
	"src/framework/renderer/renderer_backend.h" 
	"src/framework/renderer/opengl/backend_gl.h"
	"src/framework/renderer/opengl/shader_gl.h"
	"src/framework/renderer/opengl/shader_program_gl.h"

	# Game
)

# Append all project source
set(sources 
	# Framework
	# --- Core
	"src/framework/core/window.cpp"
	"src/framework/core/application.cpp"
	# --- Renderer
	"src/framework/renderer/opengl/backend_gl.cpp"
	"src/framework/renderer/opengl/shader_gl.cpp"
	"src/framework/renderer/opengl/shader_program_gl.cpp"
	"src/framework/renderer/renderer.cpp"
	"src/framework/renderer/renderer_2d.cpp"

	# Game
	"src/game/game_entry.cpp"
)

add_executable (${PROJECT_NAME} ${includes} ${sources})

target_precompile_headers(${PROJECT_NAME} PUBLIC "src/framework/pch.h")

# --------------------
#  - Third Parties -
# --------------------

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("src/framework/vendor/glfw")

# GLAD
add_subdirectory("src/framework/vendor/glad")

# Append all libs 
set(libs 
	opengl32
	glfw
	glad
)

# Include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC
		"src/framework/vendor/glfw/include"
		"src/framework/vendor/glad/include"
)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${libs})



