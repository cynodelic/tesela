// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file invert.hpp
 *
 * @brief Defines the `invert` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_INVERT_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_INVERT_HPP


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
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> invert(basic_image<PixelType>& img)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			img(ix,iy).red   = 255 - img(ix,iy).red;
			img(ix,iy).green = 255 - img(ix,iy).green;
			img(ix,iy).blue  = 255 - img(ix,iy).blue;
		}
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> invert(basic_image<PixelType>& img)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			img(ix,iy).gray = 255 - img(ix,iy).gray;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> invert(basic_image<PixelType>& img)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			img(ix,iy).red   = tdouble{1.0} - img(ix,iy).red;
			img(ix,iy).green = tdouble{1.0} - img(ix,iy).green;
			img(ix,iy).blue  = tdouble{1.0} - img(ix,iy).blue;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> invert(basic_image<PixelType>& img)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			img(ix,iy).gray = tdouble{1.0} - img(ix,iy).gray;
		}
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> invert(basic_image<PixelType>& img,const bool& inv_r,const bool& inv_g,const bool& inv_b)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			if (inv_r)
			{
				img(ix,iy).red = 255 - img(ix,iy).red;
			}

			if (inv_g)
			{
				img(ix,iy).green = 255 - img(ix,iy).green;
			}

			if (inv_b)
			{
				img(ix,iy).blue = 255 - img(ix,iy).blue;
			}

		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> invert(basic_image<PixelType>& img,const bool& inv_r,const bool& inv_g,const bool& inv_b)
{
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			if (inv_r)
			{
				img(ix,iy).red = tdouble{1.0} - img(ix,iy).red;
			}

			if (inv_g)
			{
				img(ix,iy).green = tdouble{1.0} - img(ix,iy).green;
			}

			if (inv_b)
			{
				img(ix,iy).blue = tdouble{1.0} - img(ix,iy).blue;
			}

		}
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Inverts image colors
 *
 * Inverts the colors of an image.
 *
 * @param img The image.
 */
template <typename PixelType>
void invert(basic_image<PixelType>& img);


/**
 * @ingroup filters
 * @brief Inverts image colors
 *
 * Inverts the colors of an image.
 *
 * @param img   The image.
 * @param inv_r Inverts the red channel.
 * @param inv_g Inverts the green channel.
 * @param inv_b Inverts the blue channel.
 */
template <typename PixelType>
void invert(basic_image<PixelType>& img,const bool& inv_r,const bool& inv_g,const bool& inv_b);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_INVERT_HPP
