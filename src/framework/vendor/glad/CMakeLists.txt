# --------------------------------------
#		- GLAD -
# --------------------------------------
cmake_minimum_required (VERSION 3.16)

project(glad LANGUAGES C)

set(sources
	"src/glad.c"
)

set(includes
	"include/glad/glad.h"
)

# Append the sources and includes to the STATIC lib
add_library(${PROJECT_NAME}
	STATIC
		${sources}
		${includes}
)

# Include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC
		"include"
)

