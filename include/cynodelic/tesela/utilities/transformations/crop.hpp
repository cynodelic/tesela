// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/** 
 * @file crop.hpp
 *
 * @brief Defines the `crop` function.
 */

#ifndef CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_CROP_HPP
#define CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_CROP_HPP


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
 * @brief Crops an image.
 *
 * Crops an image, given a @ref rectangle.
 *
 * @param img  The image.
 * @param rect A @ref rectangle that determines the width, the height and the
 *             position of the area to cut.
 */
template <typename PixelType>
void crop(basic_image<PixelType>& img,const rectangle& rect)
{
	std::size_t ix, iy;
	const std::size_t ow = detail::clip(rect.width,static_cast<std::size_t>(0),img.width());
	const std::size_t oh = detail::clip(rect.height,static_cast<std::size_t>(0),img.height());
	basic_image<PixelType> out(ow,oh,img.get_color_space());
	
	if ((rect.x + ow < 0) || (rect.y + oh < 0) || (rect.x + ow > img.width()) || (rect.y + oh > img.height()))
	{
		throw std::logic_error("[cynodelic::tesela::crop] The instance of \'rect\' is outside the image's boundaries.");
	}

#ifdef CYNODELIC_TESELA_OPENMP_ENABLED
	#pragma omp for private(iy,ix) schedule(dynamic)
#endif
	for (iy = 0; iy < oh; iy++)
	{
		for (ix = 0; ix < ow; ix++)
		{
			out(ix,iy) = img(rect.x + ix,rect.y + iy);
		}
	}
	
	img = std::move(out);
}


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_UTILITIES_TRANSFORMATIONS_CROP_HPP

