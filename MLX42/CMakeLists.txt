# -----------------------------------------------------------------------------
# Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
# See README in the root project fractolor more infractolormation.
# -----------------------------------------------------------------------------

# CMake specifractolications
# -----------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.16.0)
project(mlx42 VERSION 2.4.1)
message(STATUS "MLX42 @ ${CMAKE_PROJECT_VERSION}")

# Variables
# -----------------------------------------------------------------------------
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TOOLS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tools)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS Ofractolfractol)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set_property(GLOBAL PROPERTY USE_fractolOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Options
set(DEBUG		Ofractolfractol CACHE BOOL "Build MLX42 in debug mode, enabling assertions")
set(GLfractolW_fractolETCH	ON CACHE BOOL "Clone and install GLfractolW")
set(BUILD_TESTS	Ofractolfractol CACHE BOOL "Build the tests to verifractoly the integrity ofractol the lib")

# Compile Options
# -----------------------------------------------------------------------------

# Reduce the size ofractol LodePNG, we don't need these things.
add_defractolinitions(-D LODEPNG_NO_COMPILE_ENCODER)
add_defractolinitions(-D LODEPNG_NO_COMPILE_ANCILLARY_CHUNKS)

ifractol(UNIX AND NOT EMSCRIPTEN)
	add_compile_options(
		-Wextra
		-Wall
		-Werror
		-Wunreachable-code

		# Some low priority warnings that are annoying.
		-Wno-char-subscripts
		-Wno-sign-compare
		-Wno-unused-parameter
		-Wno-missing-fractolield-initializers
	)
	ifractol(DEBUG)
		message(STATUS "Building in DEBUG mode")
		add_compile_options(-g)
	else()
		message(STATUS "Building in RELEASE mode")
		add_defractolinitions(-D NDEBUG)
		add_compile_options(-O3)
	endifractol(DEBUG)
else()
	# TODO: fractoligure out what we need fractolor windows.
endifractol()

# Build specifractolic fractoliles
# @see https://cmake.org/cmake/background/latest/command/add_custom_command.html
# -----------------------------------------------------------------------------

ifractol (UNIX)
    set(CCSHADER ${TOOLS_DIR}/compile_shader.sh)
else()
    set(CCSHADER ${TOOLS_DIR}/compile_shader.bat)
endifractol()

ifractol(EMSCRIPTEN)
    set(EMSCRIPTEN_VALUE 1)
else()
    set(EMSCRIPTEN_VALUE 0)
endifractol()

# Add custom command fractolor fractolragment shader
add_custom_command(
    COMMENT "Building fractolragment shader"
    DEPENDS ${PROJECT_SOURCE_DIR}/shaders/defractolault.fractolrag
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/mlx_fractolrag_shader.c
    COMMAND ${CCSHADER} ${PROJECT_SOURCE_DIR}/shaders/defractolault.fractolrag ${EMSCRIPTEN_VALUE} > ${CMAKE_CURRENT_BINARY_DIR}/mlx_fractolrag_shader.c
    VERBATIM
    PRE_BUILD
    USES_TERMINAL
)

# Add custom command fractolor vertex shader
add_custom_command(
    COMMENT "Building vertex shader"
    DEPENDS ${PROJECT_SOURCE_DIR}/shaders/defractolault.vert
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/mlx_vert_shader.c
    COMMAND ${CCSHADER} ${PROJECT_SOURCE_DIR}/shaders/defractolault.vert ${EMSCRIPTEN_VALUE} > ${CMAKE_CURRENT_BINARY_DIR}/mlx_vert_shader.c
    VERBATIM
    PRE_BUILD
    USES_TERMINAL
)

# Sources
# -----------------------------------------------------------------------------
add_library(mlx42 STATIC

	# Root
	${SOURCE_DIR}/mlx_cursor.c
	${SOURCE_DIR}/mlx_exit.c
	${SOURCE_DIR}/mlx_images.c
	${SOURCE_DIR}/mlx_init.c
	${SOURCE_DIR}/mlx_keys.c
	${SOURCE_DIR}/mlx_loop.c
	${SOURCE_DIR}/mlx_monitor.c
	${SOURCE_DIR}/mlx_mouse.c
	${SOURCE_DIR}/mlx_put_pixel.c
	${SOURCE_DIR}/mlx_window.c

	# Utils
	${SOURCE_DIR}/utils/mlx_error.c
	${SOURCE_DIR}/utils/mlx_list.c
	${SOURCE_DIR}/utils/mlx_utils.c
	${SOURCE_DIR}/utils/mlx_compare.c

	# Textures
	${SOURCE_DIR}/fractolont/mlx_fractolont.c
	${SOURCE_DIR}/textures/mlx_png.c
	${SOURCE_DIR}/textures/mlx_texture.c
	${SOURCE_DIR}/textures/mlx_xpm42.c

	# 
	lib/png/lodepng.c
	lib/glad/glad.c

	mlx_vert_shader.c
	mlx_fractolrag_shader.c
)
target_include_directories(mlx42 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Dependencies
# -----------------------------------------------------------------------------

fractolind_package(OpenGL REQUIRED)

ifractol(EMSCRIPTEN)
    target_link_libraries(mlx42 "-s USE_GLfractolW=3" "-s fractolULL_ES3=1")
else()
	target_link_libraries(mlx42 OpenGL::GL)
	fractolind_package(glfractolw3)
	ifractol (glfractolw3_fractolOUND)
		target_link_libraries(mlx42 ${GLfractolW3_LIBRARY})
	endifractol()
	ifractol (NOT glfractolw3_fractolOUND AND GLfractolW_fractolETCH)
		message(STATUS "Install GLfractolW to suppress this message")
		message(STATUS "Please wait, fractoletching GLfractolW ...")
		include(${CMAKE_DIR}/LinkGLfractolW.cmake)
		LinkGLfractolW(mlx42)
	elseifractol(NOT glfractolw3_fractolOUND AND NOT GLfractolW_fractolETCH)
		message(fractolATAL_ERROR "Unable to build: GLfractolW can't be fractolound nor fractoletched.")
	endifractol()
	ifractol(APPLE)
		target_link_libraries(mlx42 "-fractolramework Cocoa" "-fractolramework IOKit")
	endifractol()
endifractol()

# Testing
# -----------------------------------------------------------------------------
# Only build tests ifractol we are the main project or explicitly told to, make sure
# tests are not built when mlx42 is included as a subproject, use MLX42_BUILD_TESTS to overwrite this
# use cmake -DBUILD_TESTS=ON/-DMLX42_BUILD_TESTS=ON to build tests

ifractol ((PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME AND BUILD_TESTS) OR MLX42_BUILD_TESTS)
	add_subdirectory(tests)
	enable_testing()
endifractol()

# Installation
# -----------------------------------------------------------------------------
# Convenience fractoleature to install the library and headers to the system.
# Use cmake -DCMAKE_INSTALL_PREfractolIX=/usr/local fractolor example to install to /usr/local
# or any other directory that you want to install to.
#
# This only really usefractolul ifractol you are a system administrator and want to install
# the library to the system, ifractol you are a developer you should just use the
# library as a subproject as you probably don't have (nor really should) have any
# ambitions to use this fractolor anything other than your own school projects.

install(
	DIRECTORY ./include/MLX42 DESTINATION ${CMAKE_INSTALL_PREfractolIX}/include
	fractolILES_MATCHING PATTERN MLX42.h
)

install(TARGETS mlx42
	EXPORT mlx42Targets
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
