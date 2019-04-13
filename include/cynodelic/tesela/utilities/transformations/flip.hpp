// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/** 
 * @file flip.hpp
 *
 * @brief Defines the `flip` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_FLIP_HPP
#define CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_FLIP_HPP


#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/rectangle.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup transformations
 * @brief Flips an image.
 *
 * Flips an image (left to right, up to down, etc).
 *
 * @param img The image.
 * @param hor If `true`, flips horizontally.
 * @param ver If `true`, flips vertically.
 */
template <typename PixelType>
void flip(basic_image<PixelType>& img,const bool& hor,const bool& ver)
{
	basic_image<PixelType> out(img);
	std::size_t ix, iy;

	if (hor && ver)
	{
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
		#pragma omp for private(iy,ix) schedule(dynamic)
#endif
		for (iy = 0; iy < img.height(); iy++)
		{
			for (ix = 0; ix < img.width(); ix++)
			{
				out(ix,iy) = img(img.width() - 1 - ix,img.height() - 1 - iy);
			}
		}
	}
	else if (hor && !ver)
	{
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
		#pragma omp for private(iy,ix) schedule(dynamic)
#endif
		for (iy = 0; iy < img.height(); iy++)
		{
			for (ix = 0; ix < img.width(); ix++)
			{
				if (hor)
				{
					out(ix,iy) = img(img.width() - 1 - ix,iy);
				}
			}
		}
	}
	else if (!hor && ver)
	{
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
		#pragma omp for private(iy,ix) schedule(dynamic)
#endif
		for (iy = 0; iy < img.height(); iy++)
		{
			for (ix = 0; ix < img.width(); ix++)
			{
				out(ix,iy) = img(ix,img.height() - 1 - iy);
			}
		}
	}
	
	img = std::move(out);
}


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_FLIP_HPP

