// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file type_casts.hpp
 *
 * @brief Defines type casting (conversion) functions.
 */

#ifndef CYNODELIC_TESELA_TYPE_CASTS_HPP
#define CYNODELIC_TESELA_TYPE_CASTS_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/detail/type_cast_helpers.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup typecasting
 * @brief Conversion between pixel types
 *
 * Performs conversions between two pixel types.
 *
 * @note In alpha to non-alpha conversions, the value of the alpha component is
 * lost.
 *
 * @param OutPixelT The output type.
 * @param pix       The input to convert.
 */
template <typename OutPixelT,typename InPixelT>
inline constexpr OutPixelT pixel_cast(const InPixelT& pix)
{
	return detail::pixel_cast_helper<OutPixelT>::call(pix);
}


/**
 * @ingroup typecasting
 * @brief Conversion between image types
 *
 * Performs conversions between two @ref basic_image s with different pixel
 * types.
 *
 * @note In alpha to non-alpha conversions, the value of the alpha component is
 * lost.
 * For using a different background color, use @ref remove_alpha.
 *
 * @param OutPixelT The output pixel type.
 * @param img       The input to convert.
 */
template <typename OutPixelT,typename InPixelT>
basic_image<OutPixelT> image_cast(const basic_image<InPixelT>& img)
{
	basic_image<OutPixelT> out(
		img.width(),
		img.height(),
		img.get_color_space()
	);

	for (std::size_t iy = 0; iy < out.height(); iy++)
	{
		for (std::size_t ix = 0; ix < out.width(); ix++)
		{
			out(ix,iy) = pixel_cast<OutPixelT>(img(ix,iy));
		}
	}

	return out;
}


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_TYPE_CASTS_HPP
