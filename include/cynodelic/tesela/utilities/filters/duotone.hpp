// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file duotone.hpp
 *
 * @brief Defines the `duotone` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_DUOTONE_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_DUOTONE_HPP


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
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> duotone(basic_image<PixelType>& img,const PixelType& high,const PixelType& low)
{
	double nr, ng, nb, ny;
	double tr, tg, tb;
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
			tr = detail::u8_to_dbl(high.red)*ny + detail::u8_to_dbl(low.red)*(1.0 - ny);
			tg = detail::u8_to_dbl(high.green)*ny + detail::u8_to_dbl(low.green)*(1.0 - ny);
			tb = detail::u8_to_dbl(high.blue)*ny + detail::u8_to_dbl(low.blue)*(1.0 - ny);

			img(ix,iy).red   = detail::dbl_to_u8(tr);
			img(ix,iy).green = detail::dbl_to_u8(tg);
			img(ix,iy).blue  = detail::dbl_to_u8(tb);
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> duotone(basic_image<PixelType>& img,const PixelType& high,const PixelType& low)
{
	double ny;
	double tr, tg, tb;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ny = 0.2126*img(ix,iy).red + 0.7152*img(ix,iy).green + 0.0722*img(ix,iy).blue;
			tr = high.red*ny   + low.red*(1.0 - ny);
			tg = high.green*ny + low.green*(1.0 - ny);
			tb = high.blue*ny  + low.blue*(1.0 - ny);

			img(ix,iy).red   = tr;
			img(ix,iy).green = tg;
			img(ix,iy).blue  = tb;
		}
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Duotone
 *
 * Applies a duotone filter to an image, based on the luminance of it.
 *
 * @warning This filter does not work for images with grayscale and gray-alpha
 * pixel types.
 *
 * @param img  The image.
 * @param high High color.
 * @param low  Low color.
 */
template <typename PixelType>
void duotone(basic_image<PixelType>& img,const PixelType& high,const PixelType& low);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_DUOTONE_HPP
