// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file gamma.hpp
 *
 * @brief Defines the `gamma` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_GAMMA_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_GAMMA_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cmath>
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
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> gamma(basic_image<PixelType>& img,const double& value)
{
	if (value == +0.0 || value == -0.0)
	{
		throw std::invalid_argument("[cynodelic::tesela::gamma] \'value\' must not be zero.");
	}

	std::uint8_t tr, tg, tb;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			tr = detail::dbl_to_u8(std::pow(detail::u8_to_dbl(img(ix,iy).red),1.0/value));
			tg = detail::dbl_to_u8(std::pow(detail::u8_to_dbl(img(ix,iy).green),1.0/value));
			tb = detail::dbl_to_u8(std::pow(detail::u8_to_dbl(img(ix,iy).blue),1.0/value));
			img(ix,iy).red   = tr;
			img(ix,iy).green = tg;
			img(ix,iy).blue  = tb;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> gamma(basic_image<PixelType>& img,const double& value)
{
	if (value == +0.0 || value == -0.0)
	{
		throw std::invalid_argument("[cynodelic::tesela::gamma] \'value\' must not be zero.");
	}

	double tr, tg, tb;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			tr = std::pow(img(ix,iy).red,1.0/value);
			tg = std::pow(img(ix,iy).green,1.0/value);
			tb = std::pow(img(ix,iy).blue,1.0/value);
			img(ix,iy).red   = tr;
			img(ix,iy).green = tg;
			img(ix,iy).blue  = tb;
		}
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> gamma(basic_image<PixelType>& img,const double& value)
{
	if (value == +0.0 || value == -0.0)
	{
		throw std::invalid_argument("[cynodelic::tesela::gamma] \'value\' must not be zero.");
	}

	std::uint8_t ty;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ty = detail::dbl_to_u8(std::pow(detail::u8_to_dbl(img(ix,iy).gray),1.0/value));
			img(ix,iy).gray = ty;
		}
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> gamma(basic_image<PixelType>& img,const double& value)
{
	if (value == +0.0 || value == -0.0)
	{
		throw std::invalid_argument("[cynodelic::tesela::gamma] \'value\' must not be zero.");
	}

	double ty;
	std::size_t ix, iy;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ty = std::pow(img(ix,iy).gray,1.0/value);
			img(ix,iy).gray = ty;
		}
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup filters
 * @brief Gamma
 *
 * Adjusts the gamma of an image.
 *
 * @param img   The image.
 * @param value A nonzero value corresponding to the gamma.
 */
template <typename PixelType>
void gamma(basic_image<PixelType>& img,const double& value);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_GAMMA_HPP
