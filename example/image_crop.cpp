// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file image_crop.cpp
 *
 * Crops an image.
 *
 * Usage: ./image_crop [image] [x start] [y start] [x size] [y size]
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>

#include <cynodelic/tesela/rectangle.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/utilities/transformations/crop.hpp>
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>
#include <cynodelic/tesela/image_io.hpp>

namespace tsl = cynodelic::tesela;


using my_image_io = tsl::image_io<
	tsl::jpeg_io,
	tsl::png_io,
	tsl::tiff_io
>;

int main(int /* argc */,char **argv)
{
	tsl::rgba_image img;
	my_image_io::read(argv[1],img);
	
	tsl::rectangle area(
		std::stoi(argv[2]),std::stoi(argv[3]),
		std::stoi(argv[4]),std::stoi(argv[5])
	);
	
	std::cout << "Cropping image...\n";
	std::cout << "    x: From " << area.x << " to " << (area.x + area.width) << "\n";
	std::cout << "    y: From " << area.y << " to " << (area.y + area.height) << "\n";
	
	tsl::crop(img,area);
	
	my_image_io::write("image_crop_demo.png",img);
}

