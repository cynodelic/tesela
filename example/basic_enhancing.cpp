// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file basic_enhancing.cpp
 *
 * Basic enhancing (brightness, contrast and gamma) for images.
 * Brightness and contrast should be between -1 and 1, and gamma should not
 * be 0 (zero).
 *
 * Usage: ./basic_enhancing [image] [brightness] [contrast] [gamma]
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/formats/jpeg_io.hpp>
#include <cynodelic/tesela/formats/png_io.hpp>
#include <cynodelic/tesela/formats/tiff_io.hpp>
#include <cynodelic/tesela/image_io.hpp>
#include <cynodelic/tesela/utilities/filters/brightness.hpp>
#include <cynodelic/tesela/utilities/filters/contrast.hpp>
#include <cynodelic/tesela/utilities/filters/gamma.hpp>


namespace tsl = cynodelic::tesela;


using my_image_io = tsl::image_io<
	tsl::jpeg_io,
	tsl::png_io,
	tsl::tiff_io
>;


int main(int /* argc */,char **argv)
{
	double br    = std::stod(argv[2]);
	double contr = std::stod(argv[3]);
	double gmm   = std::stod(argv[4]);
	
	std::cout << "Brightness: " << br << "\n";
	std::cout << "Contrast:   " << contr << "\n";
	std::cout << "Gamma:      " << gmm << "\n";
	
	tsl::rgba_image img;
	my_image_io::read(argv[1],img);

	tsl::brightness(img,br);
	tsl::contrast(img,contr);
	tsl::gamma(img,gmm);
	
	my_image_io::write("basic_enhancing_demo.png",img);
}

