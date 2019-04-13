# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


cmake_minimum_required(VERSION 3.11)


set(detail_header_files
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/detail/has_valid_read_write.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/transformations/detail/pix_citp_2d.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/transformations/detail/pix_lerp_2d.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/detail/tdouble_ops.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/detail/type_cast_helpers.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/detail/utils.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/detail/void_t.hpp
)


set(header_files
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/config.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/exceptions/io_error.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/formats/jpeg_io.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/formats/png_io.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/formats/tiff_io.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/image_io.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/image_types.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/literals.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/point.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/rectangle.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/rgba_types.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/tdouble.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/tesela_all.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/has_alpha.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/has_rgb_components.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/integral_form_of.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/is_grayscale.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/is_image_format_io.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/is_pixel_type.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/normalized_form_of.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/without_alpha_form.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/traits/with_alpha_form.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/type_casts.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/convert/convert_to_grayscale.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/convert/remove_alpha.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/brightness.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/contrast.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/duotone.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/gamma.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/gaussian_blur.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/invert.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/monochrome.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/filters/scatter.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/transformations/crop.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/transformations/flip.hpp
	${PROJECT_SOURCE_DIR}/include/cynodelic/tesela/utilities/transformations/scale.hpp
)


# Gets the version
file(READ include/cynodelic/tesela/config.hpp _ver_impl)

string(REGEX MATCH "#define CYNODELIC_TESELA_VERSION_MAJOR ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_tesela_ver_major ${CMAKE_MATCH_1})

string(REGEX MATCH "#define CYNODELIC_TESELA_VERSION_MINOR ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_tesela_ver_minor ${CMAKE_MATCH_1})

string(REGEX MATCH "#define CYNODELIC_TESELA_VERSION_PATCH ([0-9]+)(.*)" _ ${_ver_impl})
set(cynodelic_tesela_ver_patch ${CMAKE_MATCH_1})

set(cynodelic_tesela_ver_string "${cynodelic_tesela_ver_major}.${cynodelic_tesela_ver_minor}.${cynodelic_tesela_ver_patch}")

message("Cynodelic::Tesela, version ${cynodelic_tesela_ver_string}")


# Project name and version
project(cynodelic_tesela VERSION ${cynodelic_tesela_ver_string} LANGUAGES CXX)


# Options
option(CYNODELIC_TESELA_ALLOW_IO "Allows input/output for examples and tests" ON)
option(CYNODELIC_TESELA_BUILD_EXAMPLES "Builds the examples" OFF)
option(CYNODELIC_TESELA_BUILD_DOC "Builds the corresponding documentation" OFF)
option(CYNODELIC_TESELA_BUILD_TEST "Builds the unit tests" ON)
set(CMAKE_CXX_STANDARD 14)

set(PATH_TO_JPEG_LIBRARY "" CACHE PATH "Path to the jpeg library")
set(PATH_TO_PNG_LIBRARY "" CACHE PATH "Path to the png library")
set(PATH_TO_TIFF_LIBRARY "" CACHE PATH "Path to the tiff library")


set(JPEG_INCLUDE_DIR "${PATH_TO_JPEG_LIBRARY}/include")
set(JPEG_LIBRARY "${PATH_TO_JPEG_LIBRARY}/lib")
set(PNG_INCLUDE_DIR "${PATH_TO_PNG_LIBRARY}/include")
set(PNG_LIBRARY "${PATH_TO_PNG_LIBRARY}/lib")
set(TIFF_INCLUDE_DIR "${PATH_TO_TIFF_LIBRARY}/include")
set(TIFF_LIBRARY "${PATH_TO_TIFF_LIBRARY}/lib")

set(has_image_libs OFF)
if(PATH_TO_JPEG_LIBRARY AND PATH_TO_PNG_LIBRARY AND PATH_TO_TIFF_LIBRARY)
	set(has_image_libs ON)
	message("Path to JPEG library: ${PATH_TO_JPEG_LIBRARY}")
	message("Path to PNG library: ${PATH_TO_PNG_LIBRARY}")
	message("Path to TIFF library: ${PATH_TO_TIFF_LIBRARY}")
else()
	message("No paths for the image libraries were set. The examples cannot be built.")
endif()


if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()


# Compiler parameters for image libraries
set(image_libs_includes)
set(image_libs_deps)
set(image_libs_linkers)
if(PATH_TO_JPEG_LIBRARY)
	list(APPEND image_libs_includes ${JPEG_INCLUDE_DIR})
	list(APPEND image_libs_deps ${JPEG_LIBRARY})
	list(APPEND image_libs_linkers jpeg)
endif()
if(PATH_TO_PNG_LIBRARY)
	list(APPEND image_libs_includes ${PNG_INCLUDE_DIR})
	list(APPEND image_libs_deps ${PNG_LIBRARY})
	list(APPEND image_libs_linkers z)
	list(APPEND image_libs_linkers png)
endif()
if(PATH_TO_TIFF_LIBRARY)
	list(APPEND image_libs_includes ${TIFF_INCLUDE_DIR})
	list(APPEND image_libs_deps ${TIFF_LIBRARY})
	list(APPEND image_libs_linkers tiff)
endif()


# Library operations
add_library(tesela INTERFACE)
target_sources(tesela INTERFACE $<BUILD_INTERFACE:${detail_header_files} ${header_files}>)
target_include_directories(tesela INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/cynodelic" DESTINATION include)


# Builds unit tests
if (CYNODELIC_TESELA_BUILD_TEST)
	enable_testing()
	add_subdirectory(test)
endif()


# Builds examples
if (CYNODELIC_TESELA_BUILD_EXAMPLES AND has_image_libs AND CYNODELIC_TESELA_ALLOW_IO)
	add_subdirectory(example)
endif()


# Builds documentation
if (CYNODELIC_TESELA_BUILD_DOC)
	add_subdirectory(doc)
endif()
