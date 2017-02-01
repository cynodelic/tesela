// Copyright (c) 2017 Alvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#ifndef CYNODELIC_TESELA_IMAGE_IO_HPP
#define CYNODELIC_TESELA_IMAGE_IO_HPP

/* - image_io.hpp:
 * Methods for reading and writing image files (for now,
 * JPEG, PNG and TIFF files), based on their extensions.
 */

#include "internal.hpp"
#include "types.hpp"
#include "formats/jpeg_fmt.hpp"
#include "formats/png_fmt.hpp"
#include "formats/tiff_fmt.hpp"

namespace cynodelic { namespace tesela {

int image_read(const char* file_name,image& img)
{
	std::regex valid_ext(CYNODELIC_TESELA_IMAGE_EXTENSIONS_REGEX,std::regex::ECMAScript);
	if (std::regex_match(file_name,valid_ext))
	{
		std::regex valid_jpg_ext(CYNODELIC_TESELA_JPEG_EXTENSION_REGEX,std::regex::ECMAScript);
		std::regex valid_png_ext(CYNODELIC_TESELA_PNG_EXTENSION_REGEX, std::regex::ECMAScript);
		std::regex valid_tif_ext(CYNODELIC_TESELA_TIFF_EXTENSION_REGEX,std::regex::ECMAScript);
		if      (std::regex_match(file_name,valid_jpg_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_read] Reading JPEG file " << file_name << " according to file extension...\n";
#endif
			formats::jpeg_fmt::read(strdup(file_name),img);
		}
		else if (std::regex_match(file_name,valid_png_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_read] Reading PNG file " << file_name << " according to file extension...\n";
#endif
			formats::png_fmt::read(strdup(file_name),img);
		}
		else if (std::regex_match(file_name,valid_tif_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_read] Reading TIFF file " << file_name << " according to file extension...\n";
#endif
			formats::tiff_fmt::read(strdup(file_name),img);
		}
		else
		{
			std::cerr << "[cynodelic::tesela::image_read] Could not read " << file_name << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		std::cerr << "[cynodelic::tesela::tesela::image_read] " << file_name << "is not a valid image file.\n";
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

int image_write(const char* file_name,image& img)
{
	std::regex valid_ext(CYNODELIC_TESELA_IMAGE_EXTENSIONS_REGEX,std::regex::ECMAScript);
	if (std::regex_match(file_name,valid_ext))
	{
		std::regex valid_jpg_ext(CYNODELIC_TESELA_JPEG_EXTENSION_REGEX,std::regex::ECMAScript);
		std::regex valid_png_ext(CYNODELIC_TESELA_PNG_EXTENSION_REGEX, std::regex::ECMAScript);
		std::regex valid_tif_ext(CYNODELIC_TESELA_TIFF_EXTENSION_REGEX,std::regex::ECMAScript);
		if      (std::regex_match(file_name,valid_jpg_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_write] Writing JPEG file " << file_name << " according to file extension...\n";
#endif
			formats::jpeg_fmt::write(strdup(file_name),img);
		}
		else if (std::regex_match(file_name,valid_png_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_write] Writing PNG file " << file_name << " according to file extension...\n";
#endif
			formats::png_fmt::write(strdup(file_name),img);
		}
		else if (std::regex_match(file_name,valid_tif_ext))
		{
#ifdef CYNODELIC_TESELA_VERBOSE
			std::cout << "[cynodelic::tesela::image_write] Writing TIFF file " << file_name << " according to file extension...\n";
#endif
			formats::tiff_fmt::write(strdup(file_name),img);
		}
		else
		{
			std::cerr << "[cynodelic::tesela::image_write] Could not write " << file_name << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		std::cerr << "[cynodelic::tesela::image_write] " << file_name << "has not a valid image file extension.\n";
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

}} // end of "cynodelic::tesela" namespace

#endif
