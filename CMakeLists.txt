# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.16)

project ("LiverSandbox" LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# Allow for all warnings
add_compile_options(-DWall )

# Append all project includes
set(includes
	# Framework
	"src/framework/liver.h"
	# --- Core
	"src/framework/core/common.h"
	"src/framework/core/window.h"
	"src/framework/core/application.h"
	"src/framework/core/camera.h"
	"src/framework/core/input.h"
	"src/framework/core/math/math.h"
	"src/framework/core/math/transform.h"
	# --- Renderer
	"src/framework/renderer/renderer.h" 
	"src/framework/renderer/renderer_2d.h" 
	"src/framework/renderer/renderer_backend.h" 
	"src/framework/renderer/texture.h"
	"src/framework/renderer/opengl/texture_gl.h"
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
	"src/framework/core/camera.cpp"
	"src/framework/core/input.cpp"
	"src/framework/core/math/transform.cpp"
	# --- Renderer
	"src/framework/renderer/texture.cpp"
	"src/framework/renderer/opengl/texture_gl.cpp"
	"src/framework/renderer/opengl/backend_gl.cpp"
	"src/framework/renderer/opengl/shader_gl.cpp"
	"src/framework/renderer/opengl/shader_program_gl.cpp"
	"src/framework/renderer/renderer_backend.cpp" 
	"src/framework/renderer/renderer.cpp"
	"src/framework/renderer/renderer_2d.cpp"

	# Game
)

add_executable (${PROJECT_NAME} ${includes} ${sources}
	"src/game/game_entry.cpp")

target_precompile_headers(${PROJECT_NAME} PUBLIC "src/framework/pch.h")

# --------------------
#  - Third Parties -
# --------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/src/framework/vendor/")

# OpenGL
# TODO(devon): Use defines to detemine if this needs to be skipped
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("src/framework/vendor/glfw")

# GLAD
add_subdirectory("src/framework/vendor/glad")

# GLM
add_subdirectory("src/framework/vendor/glm")

# Append all libs 
set(libs 
	opengl32
	glfw
	glad
	glm
)

# Include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC
		"src/framework/vendor/glfw/include"
		"src/framework/vendor/glad/include"
		"src/framework/vendor/glm"
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
	${libs}
)


# -------------
# testing
# -------------
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE=1)

set(test_sources 
	"src/framework/tests/main.cpp"
	"src/framework/tests/test_input.cpp"
)

add_subdirectory("src/framework/vendor/googletest")
include_directories("${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}")

add_executable(liver_tests ${includes} ${sources} ${test_sources})

target_precompile_headers(liver_tests PUBLIC "src/framework/pch.h")
target_include_directories(liver_tests
	PUBLIC
		"src/framework/vendor/glfw/include"
		"src/framework/vendor/glad/include"
		"src/framework/vendor/glm"
)
target_link_libraries(liver_tests 
	${libs}
	gtest
	gtest_main
)


add_test(NAME "liver_testing" COMMAND liver_tests)
