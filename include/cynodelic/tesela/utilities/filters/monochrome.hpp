// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file monochrome.hpp
 *
 * @brief Defines the `monochrome` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_MONOCHROME_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_MONOCHROME_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <type_traits>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/traits/is_normalized.hpp>
#include <cynodelic/tesela/traits/has_rgb_components.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> monochrome(basic_image<PixelType>& img)
{
	double nr, ng, nb, ny;
	std::size_t ix, iy;

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
			img(ix,iy).red = img(ix,iy).green = img(ix,iy).blue = (detail::dbl_to_u8(ny));
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> monochrome(basic_image<PixelType>& img)
{
	tdouble nr, ng, nb, ny;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ny = 0.2126*img(ix,iy).red + 0.7152*img(ix,iy).green + 0.0722*img(ix,iy).blue;
			img(ix,iy).red = img(ix,iy).green = img(ix,iy).blue = tdouble(ny);
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_grayscale<PixelType>::value,void> monochrome(basic_image<PixelType>& img)
{
	return;
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Grayscale
 *
 * Turns an image into grayscale (i.e. black and white).
 *
 * @note This filter does nothing for images with grayscale and gray-alpha
 * pixel types, since they are already monochrome. 
 *
 * @param img The image.
 */
template <typename PixelType>
void monochrome(basic_image<PixelType>& img);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_MONOCHROME_HPP
