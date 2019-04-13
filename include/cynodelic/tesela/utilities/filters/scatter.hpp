// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file scatter.hpp
 *
 * @brief Defines the `scatter` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_FILTERS_SCATTER_HPP
#define CYNODELIC_TESELA_UTILITIES_FILTERS_SCATTER_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <random>
#include <cfloat>
#include <utility>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/detail/utils.hpp>
#include <cynodelic/tesela/image_types.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup filters
 * @brief Scatter
 *
 * Spreads randomly the pixels of an image.
 *
 * @param img  The image.
 * @param rgen A random number engine, like the ones in the `<random>` standard
 *             library header.
 * @param r    The radius.
 */
template <typename PixelType,class RandomNumberEngine>
void scatter(basic_image<PixelType>& img,RandomNumberEngine& rgen,double r = 1.0)
{
	basic_image<PixelType> tmp(img);
	
	std::uniform_real_distribution<double> dst(0,2.0 - DBL_EPSILON);
	
	std::size_t  ix, iy;
	std::int32_t xp, yp;
	double ang;
	
#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < img.height(); iy++)
	{
		for (ix = 0; ix < img.width(); ix++)
		{
			ang = dst(rgen);
			xp = static_cast<std::int32_t>(static_cast<double>(ix) + r*std::cos(detail::pi*ang));
			yp = static_cast<std::int32_t>(static_cast<double>(iy) + r*std::sin(detail::pi*ang));
			xp = detail::clip(xp,0,static_cast<std::int32_t>(img.width() - 1));
			yp = detail::clip(yp,0,static_cast<std::int32_t>(img.height() - 1));
			tmp(ix,iy) = img(static_cast<std::size_t>(xp),static_cast<std::size_t>(yp));
		}
	}
	
	img = std::move(tmp);
}


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_FILTERS_SCATTER_HPP
