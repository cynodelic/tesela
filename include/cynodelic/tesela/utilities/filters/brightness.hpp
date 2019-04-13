// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file brightness.hpp
 *
 * @brief Defines the `brightness` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_BRIGHTNESS_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_BRIGHTNESS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <type_traits>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/traits/is_normalized.hpp>
#include <cynodelic/tesela/traits/has_rgb_components.hpp>
#include <cynodelic/tesela/traits/is_grayscale.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> brightness(basic_image<PixelType>& img,const double& value)
{
	std::uint8_t tr, tg, tb;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			tr = static_cast<std::uint8_t>(
				detail::clip(
					static_cast<double>(img(ix,iy).red) + 255.0*value,
					0.0,
					255.0
				)
			);
			tg = static_cast<std::uint8_t>(
				detail::clip(
					static_cast<double>(img(ix,iy).green) + 255.0*value,
					0.0,
					255.0
				)
			);
			tb = static_cast<std::uint8_t>(
				detail::clip(
					static_cast<double>(img(ix,iy).blue) + 255.0*value,
					0.0,
					255.0
				)
			);
			img(ix,iy).red   = tr;
			img(ix,iy).green = tg;
			img(ix,iy).blue  = tb;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> brightness(basic_image<PixelType>& img,const double& value)
{
	double tr, tg, tb;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			tr = detail::clip(static_cast<double>(img(ix,iy).red) + value,0.0,1.0);
			tg = detail::clip(static_cast<double>(img(ix,iy).green) + value,0.0,1.0);
			tb = detail::clip(static_cast<double>(img(ix,iy).blue) + value,0.0,1.0);
			img(ix,iy).red   = tr;
			img(ix,iy).green = tg;
			img(ix,iy).blue  = tb;
		}
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> brightness(basic_image<PixelType>& img,const double& value)
{
	std::uint8_t ty;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ty = static_cast<std::uint8_t>(
				detail::clip(
					static_cast<double>(img(ix,iy).gray) + 255.0*value,
					0.0,
					255.0
				)
			);
			img(ix,iy).gray = ty;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> brightness(basic_image<PixelType>& img,const double& value)
{
	double ty;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ty = detail::clip(static_cast<double>(img(ix,iy).gray) + value,0.0,1.0);
			img(ix,iy).gray = ty;
		}
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Brightness
 *
 * Adjusts the brightness of an image.
 *
 * @param img   The image.
 * @param value Brightness (between -1.0 and 1.0).
 */
template <typename PixelType>
void brightness(basic_image<PixelType>& img,const double& value);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_BRIGHTNESS_HPP
