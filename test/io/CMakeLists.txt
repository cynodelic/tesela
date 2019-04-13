# Copyright (c) 2019 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt


add_test(NAME io COMMAND test_io --run-all)

set(test_images
	jpeg_gray_test.jpg
	jpeg_rgb_test.jpg
	png_ga_test.png
	png_gray_test.png
	png_rgba_test.png
	png_rgb_test.png
	tiff_ga_test.tif
	tiff_gray_test.tif
	tiff_rgba_test.tif
	tiff_rgb_test.tif
)

foreach(img_file_name ${test_images})
	message("Copying ${img_file_name}...")
	file(COPY ${PROJECT_SOURCE_DIR}/test/io/data/${img_file_name} DESTINATION ${PROJECT_BINARY_DIR}/test/io/data)
endforeach()

add_executable(test_io main.cpp)
link_directories(test_io PRIVATE ${image_libs_deps})
target_link_libraries(test_io ${image_libs_linkers})
target_include_directories(test_io PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include ${image_libs_libraries})
