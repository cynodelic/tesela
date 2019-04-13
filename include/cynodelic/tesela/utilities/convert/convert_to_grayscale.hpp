// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file convert_to_grayscale.hpp
 *
 * @brief Defines the `convert_to_grayscale` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_CONVERT_CONVERT_TO_GRAYSCALE_HPP
#define CYNODELIC_TESELA_UTILITIES_CONVERT_CONVERT_TO_GRAYSCALE_HPP


#include <cstdlib>
#include <type_traits>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>
#include <cynodelic/tesela/traits/is_normalized.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && !is_grayscale<PixelType>::value,void> convert_to_grayscale(basic_image<PixelType>& img,bool write_as_grayscale = true)
{
	double nr, ng, nb, ny;
	std::size_t iy, ix;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			nr = detail::u8_to_dbl(img(ix,iy).red);
			ng = detail::u8_to_dbl(img(ix,iy).green);
			nb = detail::u8_to_dbl(img(ix,iy).blue);
			ny = 0.2126*nr + 0.7152*ng + 0.0722*nb;
			img(ix,iy).red = img(ix,iy).green = img(ix,iy).blue = detail::dbl_to_u8(ny);
		}
	}

	if (write_as_grayscale)
	{
		if (img.get_color_space() == color_space::rgb)
			img.write_with_color_space(color_space::gray);
		else if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::ga);
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> convert_to_grayscale(basic_image<PixelType>& img,bool write_as_grayscale = true)
{
	if (write_as_grayscale)
	{
		if (img.get_color_space() == color_space::rgb)
			img.write_with_color_space(color_space::gray);
		else if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::ga);
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && !is_grayscale<PixelType>::value,void> convert_to_grayscale(basic_image<PixelType>& img,bool write_as_grayscale = true)
{
	double nr, ng, nb, ny;
	std::size_t iy, ix;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			nr = img(ix,iy).red;
			ng = img(ix,iy).green;
			nb = img(ix,iy).blue;
			ny = 0.2126*nr + 0.7152*ng + 0.0722*nb;
			img(ix,iy).red = img(ix,iy).green = img(ix,iy).blue = tdouble(ny);
		}
	}

	if (write_as_grayscale)
	{
		if (img.get_color_space() == color_space::rgb)
			img.write_with_color_space(color_space::gray);
		else if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::ga);
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> convert_to_grayscale(basic_image<PixelType>& img,bool write_as_grayscale = true)
{
	if (write_as_grayscale)
	{
		if (img.get_color_space() == color_space::rgb)
			img.write_with_color_space(color_space::gray);
		else if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::ga);
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup convert
 * @brief Converts an image to grayscale
 *
 * Converts an image to grayscale, for writting it as grayscale later.
 *
 * @param img                The image.
 * @param write_as_grayscale Save as a grayscale image file.
 */
template <typename PixelType>
void convert_to_grayscale(basic_image<PixelType>& img,bool write_as_grayscale = true);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_CONVERT_CONVERT_TO_GRAYSCALE_HPP
