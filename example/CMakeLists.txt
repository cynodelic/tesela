# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


set(example_names
	basic_enhancing
	converter
	gaussian_blur
	image_crop
	literals
	plasma
)

foreach(example_nm ${example_names})
	add_executable(${example_nm} ${example_nm}.cpp)
	link_directories(${example_nm} PRIVATE ${image_libs_deps})
	target_link_libraries(${example_nm} ${image_libs_linkers})
	target_include_directories(${example_nm} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include ${image_libs_libraries})
endforeach()
