// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file gaussian_blur.cpp
 *
 * Applies a Gaussian blur effect to an image.
 *
 * Note: Tesela's gaussian blur filter has an O(n^4) complexity,
 * but I encourage you to make a faster one.
 *
 * Usage: ./gaussian_blur [image] [blur size]
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>

#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>
#include <cynodelic/tesela/image_io.hpp>
#include <cynodelic/tesela/utilities/filters/gaussian_blur.hpp>


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
	
	int rad = std::stoi(argv[2]);
	
	std::cout << "Blur radius: " << rad << "\n";
	
	tsl::gaussian_blur(img,rad);
	
	my_image_io::write("gaussian_blur_demo.png",img);
}

