// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file remove_alpha.hpp
 *
 * @brief Defines the `remove_alpha` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_CONVERT_REMOVE_ALPHA_HPP
#define CYNODELIC_TESELA_UTILITIES_CONVERT_REMOVE_ALPHA_HPP


#include <cstdlib>
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
std::enable_if_t<!is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> remove_alpha(basic_image<PixelType>& img,const PixelType& alpha_fill,bool write_non_alpha = true)
{
	double nr, ng, nb, na, dr, dg, db;
	const double nfr = detail::u8_to_dbl(alpha_fill.red);
	const double nfg = detail::u8_to_dbl(alpha_fill.green);
	const double nfb = detail::u8_to_dbl(alpha_fill.blue);

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
			na = detail::u8_to_dbl(img(ix,iy).alpha);

			dr = ((1.0 - na)*nfr) + (na*nr);
			dg = ((1.0 - na)*nfg) + (na*ng);
			db = ((1.0 - na)*nfb) + (na*nb);

			img(ix,iy).red   = detail::dbl_to_u8(dr);
			img(ix,iy).green = detail::dbl_to_u8(dg);
			img(ix,iy).blue  = detail::dbl_to_u8(db);
			img(ix,iy).alpha = 255;
		}
	}

	if (write_non_alpha)
	{
		if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::rgb);
		else if (img.get_color_space() == color_space::ga)
			img.write_with_color_space(color_space::gray);
	}
}


template <typename PixelType>
std::enable_if_t<!is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> remove_alpha(basic_image<PixelType>& img,const PixelType& alpha_fill,bool write_non_alpha = true)
{
	double nr, ng, nb, na, dr, dg, db;
	const double nfr = detail::u8_to_dbl(alpha_fill.gray);

	std::size_t iy, ix;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			nr = detail::u8_to_dbl(img(ix,iy).gray);
			na = detail::u8_to_dbl(img(ix,iy).alpha);

			dr = ((1.0 - na)*nfr) + (na*nr);

			img(ix,iy).gray  = detail::dbl_to_u8(dr);
			img(ix,iy).alpha = 255;
		}
	}

	if (write_non_alpha)
	{
		if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::rgb);
		else if (img.get_color_space() == color_space::ga)
			img.write_with_color_space(color_space::gray);
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && has_rgb_components<PixelType>::value,void> remove_alpha(basic_image<PixelType>& img,const PixelType& alpha_fill,bool write_non_alpha = true)
{
	double nr, ng, nb, na, dr, dg, db;
	const double nfr = alpha_fill.red;
	const double nfg = alpha_fill.green;
	const double nfb = alpha_fill.blue;
	
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
			na = img(ix,iy).alpha;

			dr = ((1.0 - na)*nfr) + (na*nr);
			dg = ((1.0 - na)*nfg) + (na*ng);
			db = ((1.0 - na)*nfb) + (na*nb);

			img(ix,iy).red   = dr;
			img(ix,iy).green = dg;
			img(ix,iy).blue  = db;
			img(ix,iy).alpha = 1.0;
		}
	}

	if (write_non_alpha)
	{
		if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::rgb);
		else if (img.get_color_space() == color_space::ga)
			img.write_with_color_space(color_space::gray);
	}
}


template <typename PixelType>
std::enable_if_t<is_normalized<PixelType>::value && is_grayscale<PixelType>::value,void> remove_alpha(basic_image<PixelType>& img,const PixelType& alpha_fill,bool write_non_alpha = true)
{
	double nr, ng, nb, na, dr, dg, db;
	const double nfr = alpha_fill.gray;
	
	std::size_t iy, ix;

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			nr = img(ix,iy).gray;
			na = img(ix,iy).alpha;

			dr = ((1.0 - na)*nfr) + (na*nr);

			img(ix,iy).gray  = dr;
			img(ix,iy).alpha = 1.0;
		}
	}

	if (write_non_alpha)
	{
		if (img.get_color_space() == color_space::rgba)
			img.write_with_color_space(color_space::rgb);
		else if (img.get_color_space() == color_space::ga)
			img.write_with_color_space(color_space::gray);
	}
}

#else // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @ingroup convert
 * @brief Removes the transparency from an image
 *
 * Removes the transparency from an image.
 *
 * @param img             The image.
 * @param alpha_fill      The _background_ color.
 * @param write_non_alpha Write as a non-alpha RGB image file later.
 */
template <typename PixelType>
void remove_alpha(basic_image<PixelType>& img,const PixelType& alpha_fill,bool write_non_alpha = true);

#endif // DOXYGEN_SHOULD_SKIP_THIS


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_CONVERT_REMOVE_ALPHA_HPP
