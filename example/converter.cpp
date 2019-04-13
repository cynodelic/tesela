// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/*
 * @file converter.cpp
 *
 * A simple image converter.
 *
 * Usage: ./converter [image] [format]
 * Values for format: 0 (JPEG), 1 (PNG), 2 (TIFF)
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
#include <cynodelic/tesela/utilities/convert/remove_alpha.hpp>


namespace tsl = cynodelic::tesela;


using my_image_io = tsl::image_io<
	tsl::jpeg_io,
	tsl::png_io,
	tsl::tiff_io
>;


int main(int /* argc */,char **argv)
{
	std::string out_name = "converter_demo";
	int fid = std::stoi(argv[2]);
	
	std::cout << "Converting " << argv[1] << " to "
	          << ((fid == 0) ? "JPEG" : ((fid == 1) ? "PNG" : ((fid == 2) ? "TIFF" : "???")))
	          << "\n";
	
	tsl::rgba_image img;
	my_image_io::read(argv[1],img);
	
	switch (fid)
	{
		case 0:
			tsl::remove_alpha(img,tsl::rgba_t(255,255,255,255));
			out_name += ".jpg";
			break;
		case 1:
			out_name += ".png";
			break;
		case 2:
			out_name += ".tif";
			break;
		default:
			std::cout << "No valid option was selected.\n";
			std::exit(EXIT_FAILURE);
	}
	
	std::cout << "File name: " << out_name << "\n";
	my_image_io::write(out_name,img);
}

